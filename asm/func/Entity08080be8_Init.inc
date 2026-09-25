	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r5, [sp, #0x14]
	ldr r4, [sp, #0x30]
	ldr r6, [sp, #0x34]
	str r1, [r7, #0x18]
	adds r0, #0xbc
	movs r1, #0
	strh r2, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r5, [r0]
	adds r0, #2
	mov r2, sp
	ldrh r2, [r2, #0x18]
	strh r2, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #5
	strb r1, [r0]
	adds r0, #4
	strb r6, [r0]
	adds r0, r7, #0
	ldr r1, [sp, #0x1c]
	bl Entity08080be8_SetupSprite
	adds r0, r7, #0
	ldr r1, [sp, #0x20]
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x28]
	bl FUN_08080a44
	adds r0, r7, #0
	bl FUN_08080204
	adds r0, r7, #0
	ldr r1, [sp, #0x2c]
	bl FUN_08080af4
	ldr r0, [r7, #0x18]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #5
	beq _08080BD4
	ldr r1, _08080BD0 @ =FUN_080806ec
	adds r0, r7, #0
	bl Entity08080be8_SetState
	b _08080BDC
	.align 2, 0
_08080BD0: .4byte FUN_080806ec
_08080BD4:
	ldr r1, _08080BE4 @ =FUN_080807f4
	adds r0, r7, #0
	bl Entity08080be8_SetState
_08080BDC:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08080BE4: .4byte FUN_080807f4
