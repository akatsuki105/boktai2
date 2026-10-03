	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080963B0 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809638E
	movs r0, #0x87
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0809638E:
	ldrh r0, [r4]
	adds r1, r0, #1
	strh r1, [r4]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _080963D0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080963B8
	ldr r2, _080963B4 @ =0x00001BE6
	adds r1, r5, r2
	b _080963DC
	.align 2, 0
_080963B0: .4byte 0x000009EE
_080963B4: .4byte 0x00001BE6
_080963B8:
	ldrh r1, [r4]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x46
	subs r1, r1, r0
	ldr r2, _080963CC @ =0x00001BE6
	adds r0, r5, r2
	strh r1, [r0]
	b _080963EE
	.align 2, 0
_080963CC: .4byte 0x00001BE6
_080963D0:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080963E8
	ldr r0, _080963E4 @ =0x00001BE6
	adds r1, r5, r0
_080963DC:
	movs r0, #0x46
	strh r0, [r1]
	b _080963EE
	.align 2, 0
_080963E4: .4byte 0x00001BE6
_080963E8:
	adds r0, r5, #0
	bl FUN_08095a5c
_080963EE:
	pop {r4, r5}
	pop {r0}
	bx r0
