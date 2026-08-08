	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, _080E44DC @ =0x03002BE0
	ldr r3, [r0]
	cmp r3, #0
	bne _080E4460
	b _080E4898
_080E4460:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ldr r1, [r3, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _080E446E
	b _080E4898
_080E446E:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	beq _080E447A
	b _080E4898
_080E447A:
	movs r0, #8
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _080E448C
	b _080E4898
_080E448C:
	movs r0, #9
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	mov sb, r3
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r2, sp
	add r4, sp, #8
	adds r3, #0x2c
	mov r1, sb
	ldrh r0, [r1, #0x2c]
	ldrh r1, [r4]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldrb r5, [r6, #5]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	subs r5, r0, r5
	cmp r5, #0x80
	ble _080E44E4
	ldr r4, _080E44E0 @ =0xFFFFFF00
	adds r5, r5, r4
	b _080E44F2
	.align 2, 0
_080E44DC: .4byte 0x03002BE0
_080E44E0: .4byte 0xFFFFFF00
_080E44E4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r5, r0
	bge _080E44F2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r5, r5, r0
_080E44F2:
	mov r4, sb
	adds r4, #0x2c
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_080e4384
	lsls r0, r0, #0x18
	str r4, [sp, #0x18]
	cmp r0, #0
	beq _080E451E
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #1
	str r0, [r1]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	mov r0, sb
	adds r0, #0x24
	str r0, [r1]
	b _080E48BA
_080E451E:
	adds r1, r5, #0
	cmp r1, #0
	bge _080E4526
	rsbs r1, r1, #0
_080E4526:
	ldr r4, _080E457C @ =0x000001FD
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r1, r0
	ble _080E4532
	b _080E4898
_080E4532:
	mov r2, sp
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	str r1, [sp, #0x14]
	ldr r0, _080E4580 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080E4560
	ldr r0, _080E4584 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080E4560
	movs r1, #1
_080E4560:
	cmp r1, #0
	bne _080E4596
	movs r1, #0x20
	ldr r0, _080E4588 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080E458C @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E4590
	movs r0, #1
	b _080E4592
	.align 2, 0
_080E457C: .4byte 0x000001FD
_080E4580: .4byte 0x03002B8C
_080E4584: .4byte 0x03002B60
_080E4588: .4byte 0x030046A0
_080E458C: .4byte 0x00000934
_080E4590:
	movs r0, #0
_080E4592:
	cmp r0, #0
	bne _080E45CE
_080E4596:
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	lsrs r5, r0, #1
	movs r1, #8
	ldr r4, _080E45B4 @ =0x00000474
	adds r0, r6, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E45B8
	movs r0, #1
	b _080E45BA
	.align 2, 0
_080E45B4: .4byte 0x00000474
_080E45B8:
	movs r0, #0
_080E45BA:
	cmp r0, #0
	beq _080E45C2
	mov sl, r5
	b _080E45E0
_080E45C2:
	lsls r0, r5, #3
	subs r0, r0, r5
	movs r1, #0xa
	bl Div
	b _080E45DE
_080E45CE:
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
_080E45DE:
	mov sl, r0
_080E45E0:
	ldr r3, [sp, #0x14]
	cmp r3, r5
	ble _080E45E8
	b _080E4898
_080E45E8:
	ldr r0, _080E461C @ =0x7FFFFFFF
	cmp r3, r0
	ble _080E45F0
	b _080E4898
_080E45F0:
	mov r4, sb
	ldr r0, [r4, #0x3c]
	ldrh r5, [r0, #6]
	ldr r1, _080E4620 @ =0x00000256
	adds r0, r6, r1
	ldrh r1, [r0]
	ldrh r0, [r6, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	mov r8, r0
	subs r0, r5, #1
	cmp r0, r1
	bne _080E4680
	adds r4, r5, #0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E4624
	adds r0, #4
	b _080E4630
	.align 2, 0
_080E461C: .4byte 0x7FFFFFFF
_080E4620: .4byte 0x00000256
_080E4624:
	ldr r0, _080E464C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E4630:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080E4666
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E4650
	adds r0, #4
	b _080E465C
	.align 2, 0
_080E464C: .4byte 0x030046A4
_080E4650:
	ldr r0, _080E466C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E465C:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _080E4670
_080E4666:
	movs r0, #0
	b _080E4672
	.align 2, 0
_080E466C: .4byte 0x030046A4
_080E4670:
	movs r0, #1
_080E4672:
	cmp r0, #0
	bne _080E4678
	b _080E478A
_080E4678:
	cmp r4, r5
	bne _080E467E
	b _080E4786
_080E467E:
	b _080E478A
_080E4680:
	ldr r7, _080E46A4 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r2, [r0, r3]
	adds r0, r1, r2
	cmp r5, r0
	bne _080E46E8
	adds r4, r5, #0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E46A8
	adds r0, #4
	b _080E46B2
	.align 2, 0
_080E46A4: .4byte 0x030046A4
_080E46A8:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E46B2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080E4666
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E46CC
_080E46C8:
	adds r0, #4
	b _080E46D8
_080E46CC:
	ldr r0, _080E46E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E46D8:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _080E4666
	b _080E4670
	.align 2, 0
_080E46E4: .4byte 0x030046A4
_080E46E8:
	adds r0, r5, #1
	cmp r0, r1
	bne _080E4722
	adds r4, r5, #0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E4700
	adds r0, #4
	b _080E470A
_080E4700:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E470A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080E4666
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _080E46C8
	b _080E46CC
_080E4722:
	subs r0, r1, r2
	cmp r5, r0
	bne _080E478A
	adds r4, r5, #0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E473A
	adds r0, #4
	b _080E4744
_080E473A:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E4744:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080E4774
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E475E
	adds r0, #4
	b _080E476A
_080E475E:
	ldr r0, _080E4778 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E476A:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _080E477C
_080E4774:
	movs r0, #0
	b _080E477E
	.align 2, 0
_080E4778: .4byte 0x030046A4
_080E477C:
	movs r0, #1
_080E477E:
	cmp r0, #0
	beq _080E478A
	cmp r4, r5
	bne _080E478A
_080E4786:
	movs r0, #1
	b _080E478C
_080E478A:
	movs r0, #0
_080E478C:
	cmp r0, #0
	beq _080E47F4
	mov r4, sb
	adds r4, #0x24
	str r4, [sp, #0x10]
	movs r1, #8
	ldr r2, _080E47A8 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E47AC
	movs r0, #1
	b _080E47AE
	.align 2, 0
_080E47A8: .4byte 0x00000474
_080E47AC:
	movs r0, #0
_080E47AE:
	cmp r0, #0
	bne _080E47C8
	ldr r3, _080E47EC @ =0x000004A4
	adds r0, r6, r3
	ldr r0, [r0]
	adds r1, r6, #0
	adds r1, #8
	ldr r2, [sp, #0x10]
	adds r2, #8
	bl FUN_0823599c
	cmp r0, #0
	beq _080E4898
_080E47C8:
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	str r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r4, [r0]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, _080E47F0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	b _080E48BA
	.align 2, 0
_080E47EC: .4byte 0x000004A4
_080E47F0: .4byte 0xFEFFFFFF
_080E47F4:
	add r1, sp, #8
	ldr r2, [sp, #0x18]
	adds r0, r6, #0
	bl FUN_080e3f50
	adds r5, r0, #0
	cmp r5, #0
	blt _080E4898
	cmp r5, #2
	bne _080E480C
	movs r3, #1
	b _080E481E
_080E480C:
	movs r3, #0x80
	lsls r3, r3, #1
	add r0, sp, #8
	ldr r1, [sp, #0x18]
	movs r2, #0xa
	bl FUN_082340c8
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_080E481E:
	movs r2, #8
	ldr r4, _080E4834 @ =0x00000474
	adds r1, r6, r4
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _080E4838
	movs r0, #1
	b _080E483A
	.align 2, 0
_080E4834: .4byte 0x00000474
_080E4838:
	movs r0, #0
_080E483A:
	adds r1, r0, #0
	cmp r1, #0
	bne _080E4854
	cmp r5, #2
	beq _080E484A
	ldr r0, [sp, #0x14]
	cmp r0, sl
	ble _080E4854
_080E484A:
	movs r4, #0xfc
	lsls r4, r4, #1
	adds r0, r6, r4
	str r1, [r0]
	b _080E485E
_080E4854:
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	str r0, [r1]
_080E485E:
	cmp r3, #1
	bne _080E4868
	mov r1, sb
	adds r1, #0x24
	str r1, [sp, #0x10]
_080E4868:
	ldr r3, [sp, #0x10]
	cmp r3, #0
	beq _080E48B8
	movs r1, #8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080E487C
	movs r0, #1
	b _080E487E
_080E487C:
	movs r0, #0
_080E487E:
	cmp r0, #0
	bne _080E48A0
	ldr r4, _080E489C @ =0x000004A4
	adds r0, r6, r4
	ldr r0, [r0]
	adds r1, r6, #0
	adds r1, #8
	ldr r2, [sp, #0x10]
	adds r2, #8
	bl FUN_0823599c
	cmp r0, #0
	bne _080E48A0
_080E4898:
	movs r0, #0
	b _080E48BA
	.align 2, 0
_080E489C: .4byte 0x000004A4
_080E48A0:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, [sp, #0x10]
	str r2, [r0]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, _080E48CC @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_080E48B8:
	ldr r0, [sp, #0x10]
_080E48BA:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080E48CC: .4byte 0xFEFFFFFF
