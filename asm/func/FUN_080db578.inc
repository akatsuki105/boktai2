	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _080DB5C4 @ =0x03000160
	ldr r6, [r0]
	cmp r6, #0
	bne _080DB598
	bl Entity080db520_Create
	adds r6, r0, #0
	cmp r6, #0
	bne _080DB598
	b _080DB770
_080DB598:
	adds r0, r6, #0
	bl FUN_080dad4c
	adds r7, r0, #0
	cmp r7, #0
	bne _080DB5A6
	b _080DB770
_080DB5A6:
	movs r0, #1
	strh r0, [r7, #0x3e]
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _080DB602
	bl VM_GetPC
	cmp r0, #0
	beq _080DB5C8
	bl Script_GetValue
	b _080DB5CA
	.align 2, 0
_080DB5C4: .4byte 0x03000160
_080DB5C8:
	movs r0, #0
_080DB5CA:
	adds r4, r7, #0
	adds r4, #0x9c
	strh r0, [r4]
	bl VM_GetPC
	adds r5, r4, #0
	cmp r0, #0
	beq _080DB5E0
	bl Script_GetValue
	b _080DB5E2
_080DB5E0:
	movs r0, #0
_080DB5E2:
	adds r1, r7, #0
	adds r1, #0x9e
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _080DB5F8
	bl Script_GetValue
	adds r1, r0, #0
	b _080DB5FA
_080DB5F8:
	movs r1, #0
_080DB5FA:
	adds r0, r7, #0
	adds r0, #0xa0
	strh r1, [r0]
	b _080DB614
_080DB602:
	adds r1, r7, #0
	adds r1, #0x9c
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0x9e
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r5, r1, #0
_080DB614:
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	bl GetMapAreaAt
	movs r1, #0x46
	adds r1, r1, r7
	mov r8, r1
	movs r1, #0
	mov r2, r8
	strh r0, [r2]
	movs r0, #0x40
	adds r0, r0, r7
	mov sl, r0
	strh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x48
	strh r1, [r0]
	mov sb, r7
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl AuxSprite_Setup
	adds r5, r7, #0
	adds r5, #0x2c
	ldr r1, [r6, #0x34]
	str r4, [sp]
	adds r0, r5, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r2, r3, #0
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	ands r0, r3
	mov r6, sl
	cmp r2, r0
	beq _080DB698
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080DB6A0
_080DB698:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DB6A0:
	str r0, [r7]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DB6C6
	mov r1, sb
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _080DB6D0
_080DB6C6:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DB6D0:
	mov r2, sb
	str r0, [r2]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _080DB708 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _080DB740
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DB70C
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _080DB702
	ldrb r0, [r5, #5]
_080DB702:
	subs r0, #1
	strh r0, [r5, #8]
	b _080DB71C
	.align 2, 0
_080DB708: .4byte 0x0000FFFF
_080DB70C:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _080DB71C
	strh r1, [r5, #8]
_080DB71C:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DB740
	movs r0, #1
	strb r0, [r5, #7]
_080DB740:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	movs r0, #1
	strb r0, [r2, #7]
	mov r1, r8
	ldrh r0, [r1]
	bl FUN_0809dfec
	cmp r0, #0
	beq _080DB766
	ldrh r1, [r6]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r6]
_080DB766:
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080dacc4
_080DB770:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
