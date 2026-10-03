	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	ldr r1, _08091EE8 @ =0x00003F9C
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r7, #0
	bl GetItemID
	adds r4, r0, #0
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08091F24
	cmp r4, #1
	bls _08091EB6
	cmp r4, #3
	beq _08091EB6
	cmp r4, #2
	beq _08091EB6
	cmp r4, #4
	beq _08091EB6
	cmp r4, #6
	beq _08091EB6
	cmp r4, #7
	beq _08091EB6
	cmp r4, #8
	beq _08091EB6
	cmp r4, #9
	beq _08091EB6
	cmp r4, #0xa
	bne _08091EF0
_08091EB6:
	movs r2, #0xe1
	lsls r2, r2, #3
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	movs r4, #0xde
	lsls r4, r4, #2
	adds r0, r3, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08091ED6
	lsls r2, r2, #1
_08091ED6:
	adds r0, r3, #0
	movs r1, #0
	bl Player_ApplyBadCondition
	ldr r0, _08091EEC @ =0x00003FA2
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	b _08091FEC
	.align 2, 0
_08091EE8: .4byte 0x00003F9C
_08091EEC: .4byte 0x00003FA2
_08091EF0:
	cmp r4, #0xb
	bne _08091F24
	movs r2, #0xe1
	lsls r2, r2, #2
	movs r1, #0x80
	lsls r1, r1, #5
	movs r4, #0xde
	lsls r4, r4, #2
	adds r0, r3, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08091F0C
	lsls r2, r2, #1
_08091F0C:
	adds r0, r3, #0
	movs r1, #2
	bl Player_ApplyBadCondition
	ldr r0, _08091F20 @ =0x00003FA2
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	b _08091FEC
	.align 2, 0
_08091F20: .4byte 0x00003FA2
_08091F24:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08091F50
	cmp r4, #0xd
	bne _08091F50
	movs r4, #8
	ldr r1, _08091F4C @ =0x08DAA8D8
	adds r0, r1, #0
	adds r0, #0x80
	ldrh r6, [r0, #6]
	ldrh r2, [r0, #8]
	adds r3, r1, #0
	b _08091FC0
	.align 2, 0
_08091F4C: .4byte 0x08DAA8D8
_08091F50:
	ldr r1, _08091FA4 @ =0x08DAA8D8
	lsls r0, r4, #4
	adds r0, r0, r1
	ldrh r6, [r0, #6]
	ldrh r2, [r0, #8]
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r5, r3
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r3, r1, #0
	cmp r0, #5
	bne _08091F76
	cmp r4, #1
	bne _08091F76
	rsbs r6, r6, #0
_08091F76:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	mov ip, r1
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r1, ip
	ands r0, r1
	cmp r0, #0
	beq _08091FC0
	cmp r4, #1
	bls _08091FA0
	cmp r4, #8
	beq _08091FA0
	cmp r4, #0xb
	bne _08091FA8
_08091FA0:
	lsls r6, r6, #1
	b _08091FBE
	.align 2, 0
_08091FA4: .4byte 0x08DAA8D8
_08091FA8:
	subs r0, r4, #2
	cmp r0, #2
	bls _08091FBE
	cmp r4, #6
	beq _08091FBE
	cmp r4, #7
	beq _08091FBE
	cmp r4, #9
	beq _08091FBE
	cmp r4, #0xa
	bne _08091FC0
_08091FBE:
	lsls r2, r2, #1
_08091FC0:
	ldr r1, _08091FF8 @ =0x085ACF7C
	lsls r0, r4, #4
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r3
	cmp r4, #0x14
	bne _08091FFC
	adds r0, r7, #0
	bl UncoverChocolate
	movs r0, #0
	adds r1, r7, #0
	bl GetItemID
	cmp r0, #0x14
	bne _08092004
_08091FEC:
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08091e48
	b _08092004
	.align 2, 0
_08091FF8: .4byte 0x085ACF7C
_08091FFC:
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08091e48
_08092004:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
