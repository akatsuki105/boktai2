	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080931BC @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x10
	bne _0809318A
	ldr r0, [r5, #0x40]
	bl TextBox_Start
	movs r0, #1
	bl TextBox_SetInstant
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #4
	bl TextBox_SetRect
	ldr r1, _080931C0 @ =0x00003F9D
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0xfb
	bl TextBox_ShowLine
_0809318A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _080931A8
	cmp r0, #0xf
	bls _080931B6
	ldr r0, _080931C4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080931B6
_080931A8:
	bl TextBox_Close
	ldr r1, _080931C8 @ =FUN_08093264
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_080931B6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080931BC: .4byte 0x000009EE
_080931C0: .4byte 0x00003F9D
_080931C4: .4byte 0x030044E0
_080931C8: .4byte FUN_08093264
