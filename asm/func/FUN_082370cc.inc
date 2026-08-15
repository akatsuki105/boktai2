	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	mov ip, r1
	ldr r0, [sp, #0x20]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sl, r3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r7, [r1, #0x10]
	lsls r0, r2, #3
	adds r3, r0, r7
	ldr r1, [r1, #0x18]
	ldr r0, [r3, #4]
	adds r1, r1, r0
	mov r8, r1
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	bne _08237114
	movs r0, #2
	ands r0, r6
	cmp r0, #0
	beq _08237110
	ldrh r0, [r3, #2]
	lsls r0, r0, #2
	subs r0, #4
	b _0823711A
_08237110:
	mov r5, r8
	b _0823711C
_08237114:
	ldrh r0, [r4, #0x14]
	lsls r0, r0, #2
	mov r1, r8
_0823711A:
	adds r5, r1, r0
_0823711C:
	lsls r0, r2, #3
	adds r2, r0, r7
	ldrh r1, [r4, #0x12]
	mov sb, r0
	ldrh r2, [r2]
	cmp r1, r2
	bne _08237132
	movs r0, #4
	ands r0, r6
	cmp r0, #0
	beq _08237142
_08237132:
	ldrh r2, [r5]
	mov r0, sl
	lsls r3, r0, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	mov r1, ip
	bl Sprite_SetSprite
_08237142:
	mov r0, sb
	adds r1, r0, r7
	ldrh r0, [r1]
	strh r0, [r4, #0x12]
	ldrh r0, [r1, #2]
	strh r0, [r4, #0x16]
	ldrh r1, [r5, #2]
	ldrh r0, [r4, #0x10]
	muls r0, r1, r0
	cmp r0, #0
	blt _0823715C
	asrs r0, r0, #6
	b _08237162
_0823715C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08237162:
	strh r0, [r4, #0xe]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0823716E
	movs r0, #1
	strh r0, [r4, #0xe]
_0823716E:
	strh r6, [r4, #0x18]
	mov r1, r8
	str r1, [r4, #0x54]
	mov r0, sl
	strb r0, [r4, #0x1b]
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	bne _0823719E
	movs r0, #2
	ands r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _08237190
	ldrh r0, [r4, #0x16]
	subs r0, #1
_08237190:
	strh r0, [r4, #0x14]
	movs r0, #0
	movs r1, #0
	strh r1, [r4, #0xc]
	strb r0, [r4, #0x1d]
	movs r0, #0x40
	strh r0, [r4, #0x10]
_0823719E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
