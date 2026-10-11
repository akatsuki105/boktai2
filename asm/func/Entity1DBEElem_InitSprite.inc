	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r4, r7, #0
	adds r4, #0x2c
	ldr r1, _0809FD90 @ =0x0000A680
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r4, #0
	movs r1, #0x43
	bl Video_SetAuxSpritePltt
	movs r0, #3
	strb r0, [r7, #7]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r0, r7, #0
	adds r0, #0xe4
	strb r5, [r0]
	lsls r5, r5, #0x18
	cmp r5, #0
	beq _0809FD86
	adds r4, #0x1c
	subs r0, #4
	ldrh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Mover_Init
	adds r0, r4, #0
	bl FUN_08002a48
_0809FD86:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809FD90: .4byte 0x0000A680
