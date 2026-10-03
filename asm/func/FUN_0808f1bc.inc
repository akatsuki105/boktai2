	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _0808F208 @ =0x00003544
	adds r0, r4, r1
	adds r6, r4, #0
	adds r6, #0xc0
	ldr r1, _0808F20C @ =0x0000401C
	adds r5, r4, r1
	ldrb r2, [r5]
	adds r2, #0x19
	adds r1, r6, #0
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, _0808F210 @ =0x000035A4
	adds r0, r4, r1
	ldrb r1, [r5]
	movs r2, #0x1c
	subs r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r6, #0
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, _0808F214 @ =0x00003624
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #5
	ldr r1, _0808F218 @ =0x00003626
	adds r4, r4, r1
	strh r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808F208: .4byte 0x00003544
_0808F20C: .4byte 0x0000401C
_0808F210: .4byte 0x000035A4
_0808F214: .4byte 0x00003624
_0808F218: .4byte 0x00003626
