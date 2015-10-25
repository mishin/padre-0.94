Error: "Failed to find share dir for dist..." ^

You didn't specify a custom --target_dir but forgot to make the /share directory in your project application root.

By default we expect to find a /share directory in your primary project root directory (contains your Makefile.PL or dist.ini, and the lib and t directories for example) where we will create migrations. At this time we can't automatically create this /share directory in the same way we can create all the migration files and directory for you. You need to create that directory yourself:

    mkdir share
Patches to fix this, or suggestions welcomed.

c:\Users\TOSH\Documents\GitHub\padre-0.94>
perl -Ilib -e "use Test::More;use_ok('Padre::Util');done_testing()"
perl -Ilib -e "use Test::More;use_ok('Padre::Config');done_testing()"
perl -Ilib -MCarp::Always -e "use Test::More;use_ok('Padre::Config');done_testing()"
ok 1 - use Padre::Util;

c:\Users\TOSH\Documents\GitHub\padre-0.94>

perl -Ilib -MCarp::Always -e "use Test::More;use_ok('Padre::Config');done_testing()" > error.log 2>&1