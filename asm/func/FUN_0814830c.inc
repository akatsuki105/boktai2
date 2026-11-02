	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r4, r3, r1
	ldrh r1, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081483F2
	ldr r2, _081483F8 @ =0x0000024E
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _081483F2
	movs r5, #0x38
	ands r5, r1
	cmp r5, #0
	bne _081483F2
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r3, r1
	str r5, [r0]
	ldr r2, _081483FC @ =0x00000482
	adds r1, r3, r2
	movs r6, #0
	movs r7, #1
	movs r0, #1
	strh r0, [r1]
	ldr r1, _08148400 @ =0x00000222
	adds r0, r3, r1
	strh r5, [r0]
	ldr r2, _081483F8 @ =0x0000024E
	adds r0, r3, r2
	strh r5, [r0]
	ldr r0, _08148404 @ =0xFFFFFC7F
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r1, _08148408 @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _0814839C
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r3, r1
	ldr r1, _0814840C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _08148410 @ =0xFFFFFDFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r3, r2
	strb r6, [r0]
	ldr r1, _08148414 @ =0x0000021E
	adds r0, r3, r1
	strh r5, [r0]
	subs r2, #0x1a
	adds r0, r3, r2
	strh r5, [r0]
_0814839C:
	ldr r0, _08148418 @ =0xFFFFFBFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r4, _0814841C @ =0x00000542
	adds r1, r3, r4
	movs r0, #0xff
	strb r0, [r1]
	ldr r2, _08148420 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	subs r4, #0xd5
	adds r0, r3, r4
	strb r7, [r0]
	subs r4, #2
	adds r0, r3, r4
	strb r6, [r0]
	adds r4, #0xe8
	adds r0, r3, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r3, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r3, r2
	strh r5, [r0]
	movs r1, #0x11
	subs r4, #0xeb
	adds r0, r3, r4
	strb r6, [r0]
	ldr r2, _08148424 @ =0x00000469
	adds r0, r3, r2
	strb r6, [r0]
	adds r4, #2
	adds r0, r3, r4
	strb r1, [r0]
	ldr r1, _08148428 @ =0x00000484
	adds r0, r3, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r3, r2
	strb r7, [r0]
_081483F2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081483F8: .4byte 0x0000024E
_081483FC: .4byte 0x00000482
_08148400: .4byte 0x00000222
_08148404: .4byte 0xFFFFFC7F
_08148408: .4byte 0xF3FFFFFF
_0814840C: .4byte 0xFEFFFFFF
_08148410: .4byte 0xFFFFFDFF
_08148414: .4byte 0x0000021E
_08148418: .4byte 0xFFFFFBFF
_0814841C: .4byte 0x00000542
_08148420: .4byte Enemy_ClearStateBegun
_08148424: .4byte 0x00000469
_08148428: .4byte 0x00000484
