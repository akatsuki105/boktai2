	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _0808216E
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08080e0c
_0808216E:
	ldr r2, _08082184 @ =0x0000037D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _0808217A
	b _08082456
_0808217A:
	lsls r0, r0, #2
	ldr r1, _08082188 @ =_0808218C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08082184: .4byte 0x0000037D
_08082188: .4byte _0808218C
_0808218C: @ jump table
	.4byte _080821A0 @ case 0
	.4byte _080821B8 @ case 1
	.4byte _080822D0 @ case 2
	.4byte _080823AC @ case 3
	.4byte _0808241C @ case 4
_080821A0:
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08080e0c
	b _08082456
_080821B8:
	ldr r1, _08082214 @ =0x0000037E
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r2, #0
	bne _0808226E
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _08082228
	movs r0, #4
	strb r0, [r1]
	ldr r0, _08082218 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0808221C @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r2, _08082220 @ =0x00000932
	adds r1, r4, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _08082224 @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _08082262
	.align 2, 0
_08082214: .4byte 0x0000037E
_08082218: .4byte 0x000002E6
_0808221C: .4byte 0x000002E7
_08082220: .4byte 0x00000932
_08082224: .4byte 0x00000934
_08082228:
	strb r2, [r1]
	ldr r1, _080822BC @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _080822C0 @ =0x00000932
	adds r1, r4, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _080822C4 @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #0x1e
_08082262:
	strh r0, [r1]
	ldr r2, _080822C8 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0808226E:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _0808228A
	b _08082456
_0808228A:
	movs r0, #0xcb
	bl PlaySound_082406e0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080822A4
	b _080823DC
_080822A4:
	adds r0, r4, #0
	bl FUN_08082124
	adds r1, r0, #0
	cmp r1, #0
	beq _080822B2
	b _080823F2
_080822B2:
	ldr r2, _080822CC @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _0808239A
	.align 2, 0
_080822BC: .4byte 0x000002E6
_080822C0: .4byte 0x00000932
_080822C4: .4byte 0x00000934
_080822C8: .4byte 0x0000037E
_080822CC: .4byte 0x00000404
_080822D0:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _0808232C @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _080822F6
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _080822F6
	movs r0, #0x94
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080822F6:
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _08082330 @ =0x0000095E
	adds r1, r4, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _08082334 @ =0x0000037E
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _08082338
	movs r2, #0x96
	lsls r2, r2, #4
	adds r0, r4, r2
	strh r1, [r0]
	b _08082344
	.align 2, 0
_0808232C: .4byte 0x00000404
_08082330: .4byte 0x0000095E
_08082334: .4byte 0x0000037E
_08082338:
	movs r0, #0x40
	subs r0, r0, r1
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	strh r0, [r1]
_08082344:
	ldr r0, _0808237C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _0808235C
	movs r0, #0
	strh r0, [r1]
_0808235C:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08082384
	movs r0, #0xd8
	bl sound_08240740
	ldr r2, _08082380 @ =0x00000409
	adds r0, r4, r2
	strb r5, [r0]
	b _080823DC
	.align 2, 0
_0808237C: .4byte 0x0000037E
_08082380: .4byte 0x00000409
_08082384:
	adds r0, r4, #0
	bl FUN_08082124
	cmp r0, #0
	bne _08082456
	movs r0, #0xd8
	bl sound_08240740
	ldr r1, _080823A8 @ =0x00000409
	adds r0, r4, r1
	strb r5, [r0]
_0808239A:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08080e0c
	b _08082456
	.align 2, 0
_080823A8: .4byte 0x00000409
_080823AC:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080823E8
_080823DC:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08080e0c
	b _08082456
_080823E8:
	adds r0, r4, #0
	bl FUN_08082124
	cmp r0, #0
	beq _08082456
_080823F2:
	movs r0, #0xd8
	bl PlaySound_082406e0
	ldr r2, _08082414 @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08082418 @ =0x00000404
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08080e0c
	b _08082456
	.align 2, 0
_08082414: .4byte 0x00000409
_08082418: .4byte 0x00000404
_0808241C:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082456
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _0808245C @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08082460 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08082456:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808245C: .4byte 0x000002E6
_08082460: .4byte 0x000002E7
