	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _0809DE70 @ =0x03002C68
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r0, r2
	cmp r0, #0
	bne _0809DE62
	movs r1, #0
_0809DE62:
	str r1, [r4, #0x18]
	cmp r1, #0
	bne _0809DE74
	movs r0, #1
	rsbs r0, r0, #0
	b _0809DF16
	.align 2, 0
_0809DE70: .4byte 0x03002C68
_0809DE74:
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809DEAC
	movs r3, #0xf7
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0809DEA4 @ =0x08DA9E68
	ldr r5, _0809DEA8 @ =0x00000F4C
	adds r0, r4, r5
	movs r2, #0x87
	lsls r2, r2, #4
	adds r1, r1, r2
	ldm r1!, {r2, r3, r5}
	stm r0!, {r2, r3, r5}
	ldm r1!, {r2, r3, r5}
	stm r0!, {r2, r3, r5}
	ldm r1!, {r2, r3, r5}
	stm r0!, {r2, r3, r5}
	b _0809DEC8
	.align 2, 0
_0809DEA4: .4byte 0x08DA9E68
_0809DEA8: .4byte 0x00000F4C
_0809DEAC:
	ldrb r0, [r1, #0x17]
	movs r3, #0xf7
	lsls r3, r3, #4
	adds r1, r4, r3
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _0809DEC8
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r5, _0809DF20 @ =0x00000F4C
	adds r1, r4, r5
	bl FUN_08242b14
_0809DEC8:
	ldr r0, [r4, #0x18]
	adds r0, #0x41
	ldrb r0, [r0]
	movs r2, #0xf8
	lsls r2, r2, #4
	adds r1, r4, r2
	add r3, sp, #8
	add r2, sp, #0xc
	str r2, [sp]
	add r2, sp, #4
	bl FUN_081dfa20
	adds r0, r4, #0
	bl FUN_0809dde0
	adds r0, r4, #0
	bl FUN_0809d878
	adds r0, r4, #0
	bl FUN_0809d934
	adds r0, r4, #0
	bl FUN_0809dd34
	adds r0, r4, #0
	bl FUN_0809dd68
	adds r0, r4, #0
	bl FUN_0809dd88
	ldr r3, _0809DF24 @ =0x00000F74
	adds r1, r4, r3
	movs r0, #0x1e
	str r0, [r1]
	ldr r1, _0809DF28 @ =FUN_0809d3d0
	adds r0, r4, #0
	bl FUN_0809ce90
	movs r0, #0
_0809DF16:
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809DF20: .4byte 0x00000F4C
_0809DF24: .4byte 0x00000F74
_0809DF28: .4byte FUN_0809d3d0
