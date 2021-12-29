#include <err.h>
#include <git2.h>
#include <stdbool.h>
#include <string.h>

// FIXME: Remove this
#include <err.h>

// Initialize the jinko wrapper
void jinko_git_init(void) { git_libgit2_init(); }

// Get the string associated with the last libgit2 error
const char *jinko_git_get_error(void) { return git_error_last()->message; }

static const char *compute_local_path(const char *url) {
  const char *new_path = NULL;
  const char *path = url;

  while (true) {
    new_path = strstr(path, "/");

    if (!new_path)
      return path;

    path = new_path;

    // Advance the pointer if the first character is a separator
    if (*path == '/') {
      path++;
    }
  }

  return NULL;
}

int jinko_git_clone(const char *url) {
  git_repository *repo = NULL;

  const char *local_path = compute_local_path(url);

  if (git_clone(&repo, url, local_path, NULL)) {
    warnx("%s", jinko_git_get_error());
    return -1;
  }

  return 0;
}
