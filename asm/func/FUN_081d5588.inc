	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081D5600 @ =0x03000194
	ldr r4, [r0]
	cmp r4, #0
	bne _081D5596
	b _081D5814
_081D5596:
	adds r6, r5, #0
	adds r6, #0xd6
	ldrh r1, [r6]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _081D55D2
	ldr r0, _081D5604 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D55B4
	b _081D5814
_081D55B4:
	ldr r1, _081D5608 @ =0x000012B0
	adds r0, r4, r1
	adds r1, r5, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _081D55C6
	b _081D5814
_081D55C6:
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D55D2
	b _081D5814
_081D55D2:
	adds r0, r5, #0
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D55FA
	cmp r1, #0
	blt _081D55FA
	ldr r0, _081D560C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D55FA
	ldr r0, _081D5610 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D5614
_081D55FA:
	movs r7, #0
	b _081D5622
	.align 2, 0
_081D5600: .4byte 0x03000194
_081D5604: .4byte 0x03002BE0
_081D5608: .4byte 0x000012B0
_081D560C: .4byte 0x030046A8
_081D5610: .4byte 0x030046AC
_081D5614:
	ldr r0, _081D5640 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_081D5622:
	adds r0, r5, #0
	adds r0, #0xfe
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r6, r0, #0x18
	adds r4, r7, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5644
	adds r0, #4
	b _081D5650
	.align 2, 0
_081D5640: .4byte 0x030046A4
_081D5644:
	ldr r0, _081D566C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D5650:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D5686
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5670
	adds r0, #4
	b _081D567C
	.align 2, 0
_081D566C: .4byte 0x030046A4
_081D5670:
	ldr r0, _081D568C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D567C:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5690
_081D5686:
	movs r0, #0
	b _081D5692
	.align 2, 0
_081D568C: .4byte 0x030046A4
_081D5690:
	movs r0, #1
_081D5692:
	cmp r0, #0
	beq _081D56A4
	ldr r0, _081D56A0 @ =0x00000151
	bl PlaySound_082406e0
	movs r0, #1
	b _081D56A6
	.align 2, 0
_081D56A0: .4byte 0x00000151
_081D56A4:
	movs r0, #0
_081D56A6:
	cmp r0, #0
	beq _081D56AC
	b _081D5814
_081D56AC:
	subs r4, r7, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D56BE
	adds r0, #4
	b _081D56CA
_081D56BE:
	ldr r0, _081D56E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D56CA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D56FE
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D56E8
	adds r0, #4
	b _081D56F4
	.align 2, 0
_081D56E4: .4byte 0x030046A4
_081D56E8:
	ldr r0, _081D5704 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D56F4:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5708
_081D56FE:
	movs r0, #0
	b _081D570A
	.align 2, 0
_081D5704: .4byte 0x030046A4
_081D5708:
	movs r0, #1
_081D570A:
	cmp r0, #0
	beq _081D571C
	ldr r0, _081D5718 @ =0x00000151
	bl PlaySound_082406e0
	movs r0, #1
	b _081D571E
	.align 2, 0
_081D5718: .4byte 0x00000151
_081D571C:
	movs r0, #0
_081D571E:
	cmp r0, #0
	bne _081D5814
	ldr r5, _081D5740 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r7, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5744
	adds r0, #4
	b _081D574E
	.align 2, 0
_081D5740: .4byte 0x030046A4
_081D5744:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081D574E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D577E
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D5768
	adds r0, #4
	b _081D5774
_081D5768:
	ldr r0, _081D5784 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D5774:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5788
_081D577E:
	movs r0, #0
	b _081D578A
	.align 2, 0
_081D5784: .4byte 0x030046A4
_081D5788:
	movs r0, #1
_081D578A:
	cmp r0, #0
	beq _081D579C
	ldr r0, _081D5798 @ =0x00000151
	bl PlaySound_082406e0
	movs r0, #1
	b _081D579E
	.align 2, 0
_081D5798: .4byte 0x00000151
_081D579C:
	movs r0, #0
_081D579E:
	cmp r0, #0
	bne _081D5814
	ldr r5, _081D57C0 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r7, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D57C4
	adds r0, #4
	b _081D57CE
	.align 2, 0
_081D57C0: .4byte 0x030046A4
_081D57C4:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081D57CE:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _081D57FE
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D57E8
	adds r0, #4
	b _081D57F4
_081D57E8:
	ldr r0, _081D5804 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D57F4:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081D5808
_081D57FE:
	movs r0, #0
	b _081D580A
	.align 2, 0
_081D5804: .4byte 0x030046A4
_081D5808:
	movs r0, #1
_081D580A:
	cmp r0, #0
	beq _081D5814
	ldr r0, _081D581C @ =0x00000151
	bl PlaySound_082406e0
_081D5814:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D581C: .4byte 0x00000151
