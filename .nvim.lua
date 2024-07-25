vim.keymap.set("n", "<leader>pb", function() vim.cmd("!cmake --build build") end)
vim.keymap.set("n", "<leader>pr", function() vim.cmd("!./build/bin/BFight") end)

vim.opt.shiftwidth = 4
vim.opt.tabstop = 4
vim.opt.softtabstop = 4
vim.opt.expandtab = true
