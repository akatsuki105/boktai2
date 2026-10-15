	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x9f
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _081E4994 @ =0x00000A08
	adds r0, r4, r1
	movs r5, #0
	movs r3, #0
	strh r3, [r0]
	ldr r2, _081E4998 @ =0x00000A0A
	adds r0, r4, r2
	strh r3, [r0]
	ldr r6, _081E499C @ =0x000009E8
	adds r0, r4, r6
	adds r2, #0xbe
	adds r1, r4, r2
	ldr r6, _081E49A0 @ =0x00000B2A
	adds r2, r4, r6
	ldrh r2, [r2]
	str r3, [sp]
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r0, _081E49A4 @ =0x00001623
	adds r4, r4, r0
	strb r5, [r4]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E4994: .4byte 0x00000A08
_081E4998: .4byte 0x00000A0A
_081E499C: .4byte 0x000009E8
_081E49A0: .4byte 0x00000B2A
_081E49A4: .4byte 0x00001623
