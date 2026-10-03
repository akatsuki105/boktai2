	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0809365C @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08093622
	ldr r0, _08093660 @ =0x00000259
	bl PlaySound_082406e0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_08093622:
	movs r6, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r4, r5, r1
	ldr r0, [r4]
	ldr r2, _08093664 @ =0x00000366
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x78
	bl Div
	adds r1, r0, #0
	cmp r1, #0
	bne _08093640
	movs r1, #1
_08093640:
	ldr r0, [r4]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r4, r0, r2
	ldrh r3, [r4]
	ldr r2, _08093668 @ =0x00003FA6
	adds r0, r5, r2
	ldrh r2, [r0]
	adds r0, r2, r1
	cmp r3, r0
	ble _0809366C
	subs r0, r3, r1
	strh r0, [r4]
	b _0809367C
	.align 2, 0
_0809365C: .4byte 0x000009EE
_08093660: .4byte 0x00000259
_08093664: .4byte 0x00000366
_08093668: .4byte 0x00003FA6
_0809366C:
	subs r0, r2, r1
	cmp r3, r0
	bge _08093678
	adds r0, r3, r1
	strh r0, [r4]
	b _0809367C
_08093678:
	strh r2, [r4]
	movs r6, #1
_0809367C:
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r4, r5, r0
	ldr r0, [r4]
	ldr r1, _080936B4 @ =0x0000036A
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x78
	bl Div
	adds r1, r0, #0
	cmp r1, #0
	bne _08093698
	movs r1, #1
_08093698:
	ldr r0, [r4]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r4, r0, r2
	ldrh r3, [r4]
	ldr r2, _080936B8 @ =0x00003FAA
	adds r0, r5, r2
	ldrh r2, [r0]
	adds r0, r2, r1
	cmp r3, r0
	ble _080936BC
	subs r0, r3, r1
	strh r0, [r4]
	b _080936CC
	.align 2, 0
_080936B4: .4byte 0x0000036A
_080936B8: .4byte 0x00003FAA
_080936BC:
	subs r0, r2, r1
	cmp r3, r0
	bge _080936C8
	adds r0, r3, r1
	strh r0, [r4]
	b _080936CC
_080936C8:
	strh r2, [r4]
	adds r6, #1
_080936CC:
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	cmp r6, #1
	ble _08093700
	ldr r0, _08093708 @ =0x00000259
	bl sound_08240740
	ldr r1, _0809370C @ =0x00003AEE
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_08091e64
	adds r0, r5, #0
	bl FUN_08092744
_08093700:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08093708: .4byte 0x00000259
_0809370C: .4byte 0x00003AEE
