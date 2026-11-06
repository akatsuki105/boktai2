	push {r4, r5, r6, r7, lr}
	sub sp, #8
	mov ip, r0
	ldr r4, _081F8CA0 @ =0x0203B400
	ldr r3, _081F8CA4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081F8CA8 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	mov r4, sp
	adds r6, r0, #0
	subs r6, #0x10
	ldr r1, _081F8CAC @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081F8CB0
	asrs r2, r0, #0xc
	b _081F8CB6
	.align 2, 0
_081F8CA0: .4byte 0x0203B400
_081F8CA4: .4byte 0x030046B8
_081F8CA8: .4byte 0x000003FF
_081F8CAC: .4byte gSineTable
_081F8CB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081F8CB6:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081F8CCE
	asrs r0, r0, #0xc
	b _081F8CD4
_081F8CCE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F8CD4:
	strh r0, [r4, #4]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081F8D04 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _081F8D08 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	subs r0, #0x30
	mov r1, sp
	strh r0, [r1, #2]
	mov r0, ip
	movs r2, #0x3c
	movs r3, #3
	bl Entity081ee2a0_SpawnDefault
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F8D04: .4byte 0x000003FF
_081F8D08: .4byte 0x0203B400
