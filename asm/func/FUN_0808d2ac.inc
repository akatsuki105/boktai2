	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
_0808D2B2:
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge _0808D304
	movs r0, #0x64
	adds r3, r5, #0
	muls r3, r0, r3
	ldr r0, _0808D2F8 @ =0x00000C14
	adds r2, r4, r0
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r3, r4
	ldr r1, _0808D2FC @ =0x00000C0C
	adds r0, r0, r1
	adds r3, r4, r3
	ldr r2, _0808D300 @ =0x00000C09
	adds r3, r3, r2
	movs r2, #0
	ldrsb r2, [r3, r2]
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	adds r1, #0xa0
	movs r3, #1
	bl MainSprite_SetPose
	b _0808D316
	.align 2, 0
_0808D2F8: .4byte 0x00000C14
_0808D2FC: .4byte 0x00000C0C
_0808D300: .4byte 0x00000C09
_0808D304:
	movs r0, #0x64
	muls r0, r5, r0
	ldr r1, _0808D354 @ =0x00000C14
	adds r2, r4, r1
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_0808D316:
	movs r2, #0xf4
	lsls r2, r2, #4
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r5, r0
	bge _0808D378
	movs r0, #0x68
	adds r3, r5, #0
	muls r3, r0, r3
	ldr r0, _0808D358 @ =0x00000DAC
	adds r2, r4, r0
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xda
	lsls r1, r1, #4
	adds r0, r4, r1
	adds r0, r0, r3
	ldr r1, [r0]
	cmp r1, #0
	bne _0808D360
	adds r0, r3, r4
	ldr r2, _0808D35C @ =0x00000DA4
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0
	b _0808D36C
	.align 2, 0
_0808D354: .4byte 0x00000C14
_0808D358: .4byte 0x00000DAC
_0808D35C: .4byte 0x00000DA4
_0808D360:
	adds r0, r3, r4
	ldr r2, _0808D374 @ =0x00000DA4
	adds r0, r0, r2
	ldrb r2, [r1]
	adds r1, r4, #0
	adds r1, #0xa0
_0808D36C:
	movs r3, #1
	bl MainSprite_SetPose
	b _0808D38A
	.align 2, 0
_0808D374: .4byte 0x00000DA4
_0808D378:
	movs r0, #0x68
	muls r0, r5, r0
	ldr r1, _0808D398 @ =0x00000DAC
	adds r2, r4, r1
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_0808D38A:
	adds r5, #1
	cmp r5, #3
	ble _0808D2B2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808D398: .4byte 0x00000DAC
