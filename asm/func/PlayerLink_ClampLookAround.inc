	push {r4, r5, r6, lr}
	mov ip, r0
	ldr r0, _080CF784 @ =0x000003CA
	add r0, ip
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	movs r1, #0xf2
	lsls r1, r1, #2
	add r1, ip
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r6, r0, r2
	movs r4, #0xf3
	lsls r4, r4, #2
	add r4, ip
	movs r3, #0
	ldrsh r0, [r4, r3]
	subs r5, r0, r2
	subs r3, r5, r6
	movs r0, #0xc8
	lsls r0, r0, #2
	cmp r3, r0
	ble _080CF78C
	ldr r2, _080CF788 @ =0xFFFFFCE0
	adds r0, r3, r2
	asrs r2, r0, #1
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r4]
	subs r0, r0, r2
	b _080CF7A0
	.align 2, 0
_080CF784: .4byte 0x000003CA
_080CF788: .4byte 0xFFFFFCE0
_080CF78C:
	ldr r0, _080CF7F4 @ =0xFFFFFCE0
	cmp r3, r0
	bge _080CF7A2
	subs r0, r0, r3
	asrs r2, r0, #1
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r4]
	adds r0, r0, r2
_080CF7A0:
	strh r0, [r4]
_080CF7A2:
	adds r3, r5, r6
	movs r0, #0xc8
	lsls r0, r0, #2
	cmp r3, r0
	ble _080CF7CA
	ldr r1, _080CF7F4 @ =0xFFFFFCE0
	adds r0, r3, r1
	asrs r2, r0, #1
	movs r1, #0xf2
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	movs r1, #0xf3
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
_080CF7CA:
	ldr r0, _080CF7F4 @ =0xFFFFFCE0
	cmp r3, r0
	bge _080CF7EC
	subs r0, r0, r3
	asrs r2, r0, #1
	movs r1, #0xf2
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r1, #0xf3
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_080CF7EC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CF7F4: .4byte 0xFFFFFCE0
