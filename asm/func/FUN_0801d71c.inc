	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl EntityDA0B_TakeFnChanged
	cmp r0, #0
	beq _0801D758
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0801c114
	adds r0, r4, #0
	bl FUN_0801d0e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801D768 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r0, _0801D76C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0
	bl FUN_0807c7c8
_0801D758:
	ldr r0, [r4, #0x44]
	cmp r0, #0x1f
	bls _0801D774
	ldr r1, _0801D770 @ =FUN_0801d788
	adds r0, r4, #0
	bl EntityDA0B_SetFn
	b _0801D780
	.align 2, 0
_0801D768: .4byte 0x0000FFFF
_0801D76C: .4byte 0x03002BE0
_0801D770: .4byte FUN_0801d788
_0801D774:
	adds r0, r4, #0
	bl FUN_0801d540
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
_0801D780:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
