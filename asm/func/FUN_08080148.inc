	push {r4, lr}
	adds r4, r0, #0
	str r1, [r4, #0x18]
	bl LoadPlayerSpriteSet_0807fe48
	adds r0, r4, #0
	bl FUN_0807fed0
	adds r0, r4, #0
	bl FUN_0807ff78
	ldr r1, _080801A8 @ =FUN_0807f94c
	adds r0, r4, #0
	bl FUN_0807f640
	ldr r1, _080801AC @ =0x030047A4
	ldr r0, [r1]
	movs r3, #1
	orrs r0, r3
	str r0, [r1]
	ldr r0, [r4, #0x18]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r0, r0, #1
	adds r1, r4, #0
	adds r1, #0xf2
	strh r0, [r1]
	cmp r0, #0
	bne _08080188
	strh r3, [r1]
_08080188:
	ldr r0, [r4, #0x18]
	adds r0, r0, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r1, #0x48
	bl Div
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0xf0
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080801A8: .4byte FUN_0807f94c
_080801AC: .4byte 0x030047A4
