	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _080BCD44 @ =0x000012EC
	adds r4, r5, r0
	movs r6, #0
	strb r1, [r4]
	adds r0, r5, #0
	bl FUN_080bc908
	ldrb r0, [r4]
	cmp r0, #1
	bne _080BCCE4
	adds r0, r5, #0
	bl FUN_080bc994
_080BCCE4:
	adds r0, r5, #0
	bl FUN_080bc400
	adds r0, r5, #0
	bl FUN_080bc45c
	adds r0, r5, #0
	bl FUN_080bc498
	adds r0, r5, #0
	bl FUN_080bc8c8
	adds r0, r5, #0
	bl FUN_080bca20
	ldr r1, _080BCD48 @ =0x0000151B
	adds r0, r5, r1
	strb r6, [r0]
	adds r1, #1
	adds r0, r5, r1
	strb r6, [r0]
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BCD4C @ =0x0000FFFF
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r5, #0
	bl FUN_080bb160
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080BCD50 @ =FUN_080bca50
	adds r0, r5, #0
	bl Entity3019_SetState
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BCD44: .4byte 0x000012EC
_080BCD48: .4byte 0x0000151B
_080BCD4C: .4byte 0x0000FFFF
_080BCD50: .4byte FUN_080bca50
