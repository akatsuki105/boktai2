	push {r4, r5, lr}
	sub sp, #8
	ldr r0, _0823D3E8 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, #0x3c
	bl Div
	adds r5, r0, #0
	movs r1, #0x3c
	bl Mod
	adds r0, r5, #0
	movs r1, #0x3c
	bl Div
	adds r5, r0, #0
	movs r1, #0x3c
	bl Mod
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0x3c
	bl Div
	adds r5, r0, #0
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823D3E8: .4byte gSystemSaveData
