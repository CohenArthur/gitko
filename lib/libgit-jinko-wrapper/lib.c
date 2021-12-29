#include <err.h>
#include <git2.h>
#include <stdbool.h>
#include <string.h>

// Get the string associated with the last libgit2 error. We need to perform
// this action using the wrapper since we cannot access struct fields from
// jinko yet (or pointers + an offset as that would work too here)
const char *jinko_git_get_error(void) { return git_error_last()->message; }

int jinko_git_clone(const char *url, const char *local_path) {
  git_repository *repo = NULL;

  if (git_clone(&repo, url, local_path, NULL))
    return -1;

  return 0;
}
