	push {r4, r5, lr}
	adds r5, r0, #0
	mov ip, r1
	ldrh r0, [r1, #0x3e]
	cmp r0, #0
	beq _0823664E
	b _08236762
_0823664E:
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, [r5, #0x38]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _08236660
	ldrh r1, [r5, #0x3c]
	b _08236668
_08236660:
	ldrh r1, [r5, #0x3c]
	mov r3, ip
	ldrh r0, [r3, #0x3c]
	subs r1, r1, r0
_08236668:
	cmp r1, #0
	bgt _0823666E
	movs r1, #1
_0823666E:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	beq _0823667C
	movs r3, #0
	b _08236684
_0823667C:
	mov r0, ip
	ldr r3, [r0, #0x38]
	movs r0, #0x7f
	ands r3, r0
_08236684:
	mov r0, ip
	ldr r4, [r0, #0x34]
	movs r0, #0x7f
	ands r4, r0
	ands r2, r0
	cmp r2, #0
	bne _08236698
	mov r3, ip
	strh r1, [r3, #0x3e]
	b _08236706
_08236698:
	cmp r3, #0
	bne _082366A8
	lsls r0, r1, #2
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r1, ip
	strh r0, [r1, #0x3e]
	b _08236708
_082366A8:
	cmp r3, #0x40
	bne _082366BE
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r3, ip
	strh r0, [r3, #0x3e]
	mov r1, ip
	adds r1, #0x43
	movs r0, #2
	b _0823670C
_082366BE:
	cmp r2, #0x40
	bne _082366CE
	lsls r0, r1, #2
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r1, ip
	strh r0, [r1, #0x3e]
	b _08236708
_082366CE:
	ands r3, r2
	cmp r3, #0
	beq _082366E6
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r3, ip
	strh r0, [r3, #0x3e]
	mov r1, ip
	adds r1, #0x43
	movs r0, #2
	b _0823670C
_082366E6:
	ands r4, r2
	cmp r4, #0
	beq _082366FC
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #1
	mov r1, ip
	strh r0, [r1, #0x3e]
	adds r1, #0x43
	movs r0, #4
	b _0823670C
_082366FC:
	lsls r0, r1, #2
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r3, ip
	strh r0, [r3, #0x3e]
_08236706:
	mov r1, ip
_08236708:
	adds r1, #0x43
	movs r0, #1
_0823670C:
	strb r0, [r1]
	adds r2, r1, #0
	mov r0, ip
	ldrh r1, [r0, #6]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08236756
	ldrh r1, [r5, #6]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08236756
	mov r0, ip
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x42
	ldrb r1, [r1]
	subs r0, r0, r1
	cmp r0, #0
	bge _0823673E
	rsbs r0, r0, #0
_0823673E:
	cmp r0, #0x20
	bgt _08236756
	mov r3, ip
	ldrh r1, [r3, #0x3e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsrs r0, r0, #1
	strh r0, [r3, #0x3e]
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
_08236756:
	mov r1, ip
	ldrh r0, [r1, #0x3e]
	cmp r0, #0
	bne _08236762
	movs r0, #1
	strh r0, [r1, #0x3e]
_08236762:
	pop {r4, r5}
	pop {r0}
	bx r0
