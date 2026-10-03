	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _0809A4B0 @ =0x030047B8
	movs r1, #1
	str r1, [r0]
	ldr r0, _0809A4B4 @ =0x000009EE
	adds r5, r6, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _0809A48E
	ldr r0, _0809A4B8 @ =0x00004018
	adds r4, r6, r0
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #2
	movs r2, #6
	movs r3, #0x1a
	bl TextPanel_SetRect
	ldr r0, [r4]
	ldr r1, [r6, #0x58]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #0xd
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	movs r0, #0xc
	bl FUN_08099b3c
_0809A48E:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0809A4A6
	ldr r1, _0809A4BC @ =FUN_0809a4c0
	adds r0, r6, #0
	movs r2, #1
	bl FUN_0808a354
_0809A4A6:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A4B0: .4byte 0x030047B8
_0809A4B4: .4byte 0x000009EE
_0809A4B8: .4byte 0x00004018
_0809A4BC: .4byte FUN_0809a4c0
