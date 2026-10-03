	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809324C @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080931FE
	ldr r0, [r5, #0x40]
	bl TextBox_Start
	movs r0, #1
	bl TextBox_SetInstant
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #4
	bl TextBox_SetRect
	ldr r1, _08093250 @ =0x00003F9D
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0xf9
	bl TextBox_ShowLine
_080931FE:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _0809321C
	cmp r0, #0xf
	bls _08093246
	ldr r0, _08093254 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08093246
_0809321C:
	ldr r1, _08093258 @ =0x00003AEE
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _0809325C @ =0x00000F6C
	adds r2, r5, r0
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	bl TextBox_Close
	ldr r1, _08093260 @ =FUN_08093264
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_08093246:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809324C: .4byte 0x000009EE
_08093250: .4byte 0x00003F9D
_08093254: .4byte 0x030044E0
_08093258: .4byte 0x00003AEE
_0809325C: .4byte 0x00000F6C
_08093260: .4byte FUN_08093264
