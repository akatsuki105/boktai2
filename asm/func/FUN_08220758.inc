	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	mov r8, r5
	adds r6, r5, #0
	adds r6, #0x50
	movs r2, #1
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r3, r5, r0
	ldr r0, [r3]
	ands r2, r0
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	cmp r2, #0
	beq _082207C2
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #5
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl FUN_08023090
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r5, #0
	bl FUN_08022fb8
	ldr r0, _08220814 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _082207C2
	adds r0, r5, #0
	bl FUN_0821dca0
_082207C2:
	movs r2, #0xc
	mov r1, r8
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r3, [r6]
	ldr r2, _08220818 @ =0xFFFFF830
	adds r0, r3, r2
	lsls r0, r0, #0x10
	ldr r2, _0822081C @ =0x06A40000
	adds r7, r1, #0
	cmp r0, r2
	bhi _08220888
	ldrh r0, [r6, #4]
	lsls r1, r0, #0x10
	asrs r2, r1, #0x10
	ldr r0, _08220820 @ =0x000003E7
	cmp r2, r0
	ble _08220888
	ldr r0, _08220824 @ =0x00000A8C
	cmp r2, r0
	bgt _08220888
	lsls r0, r3, #0x10
	asrs r2, r0, #0x18
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0822080E
	cmp r1, #0
	blt _0822080E
	ldr r0, _08220828 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0822080E
	ldr r0, _0822082C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08220830
_0822080E:
	movs r4, #0
	b _0822083E
	.align 2, 0
_08220814: .4byte 0x03002BE0
_08220818: .4byte 0xFFFFF830
_0822081C: .4byte 0x06A40000
_08220820: .4byte 0x000003E7
_08220824: .4byte 0x00000A8C
_08220828: .4byte 0x030046A8
_0822082C: .4byte 0x030046AC
_08220830:
	ldr r0, _08220850 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0822083E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08220854
	adds r0, #4
	b _08220860
	.align 2, 0
_08220850: .4byte 0x030046A4
_08220854:
	ldr r0, _08220874 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08220860:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08220878
	cmp r2, #2
	beq _0822087C
	b _08220880
	.align 2, 0
_08220874: .4byte 0x030046A4
_08220878:
	ldrb r0, [r6, #4]
	b _0822087E
_0822087C:
	ldrb r0, [r6]
_0822087E:
	subs r1, r1, r0
_08220880:
	movs r0, #0xa0
	lsls r0, r0, #3
	cmp r1, r0
	beq _08220900
_08220888:
	movs r0, #0
	ldrsh r2, [r6, r0]
	movs r1, #4
	ldrsh r3, [r6, r1]
	movs r0, #0xaf
	lsls r0, r0, #4
	ldr r1, _082208C0 @ =0x0000076C
	subs r0, r0, r2
	subs r1, r1, r3
	bl FUN_0823785c
	adds r4, r0, #0
	add r3, sp, #8
	movs r6, #0xa
	ldr r2, _082208C4 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _082208C8
	asrs r1, r0, #0xc
	b _082208CE
	.align 2, 0
_082208C0: .4byte 0x0000076C
_082208C4: .4byte 0x085B0A08
_082208C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_082208CE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _082208EC @ =0x085B0A08
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _082208F0
	asrs r0, r0, #0xc
	b _082208F6
	.align 2, 0
_082208EC: .4byte 0x085B0A08
_082208F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_082208F6:
	strh r0, [r3, #4]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [r5, #0x58]
	str r1, [r5, #0x5c]
_08220900:
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r6, [r0]
	cmp r6, #0
	beq _08220912
	cmp r6, #0x63
	beq _08220964
	b _0822097E
_08220912:
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r0, [r4]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	movs r1, #0xe7
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne _0822097E
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	mov r0, r8
	bl FUN_08023024
	movs r1, #0x63
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	str r6, [r0]
	ldr r0, [r4]
	movs r1, #2
	orrs r0, r1
	str r0, [r4]
	b _0822097E
_08220964:
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
_0822097E:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
