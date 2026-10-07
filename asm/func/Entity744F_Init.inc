	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_080be690
	adds r0, r4, #0
	bl FUN_080be144
	adds r0, r4, #0
	bl Entity744F_LoadBgPltt
	adds r0, r4, #0
	bl FUN_080be204
	adds r0, r4, #0
	bl FUN_080be650
	adds r0, r4, #0
	bl FUN_080be7b4
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BEA8C @ =0x0000FFFF
	str r0, [sp, #4]
	movs r5, #0
	str r5, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080BEA90 @ =0x00001654
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_080be0d8
	ldr r1, _080BEA94 @ =0x00001658
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r5, [r0]
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080BEA98 @ =FUN_080be7e4
	adds r0, r4, #0
	bl Entity744F_SetState
	movs r0, #0
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BEA8C: .4byte 0x0000FFFF
_080BEA90: .4byte 0x00001654
_080BEA94: .4byte 0x00001658
_080BEA98: .4byte FUN_080be7e4
