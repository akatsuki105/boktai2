	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r0, r1, #0
	bl VM_ParseStringRef
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	bl Textbox_LookupString
	adds r2, r0, #0
	movs r0, #0
	strb r0, [r4, #0x1b]
	adds r1, r4, #0
	adds r1, #0x3a
	strb r0, [r1]
	movs r3, #0
	adds r7, r4, #0
	adds r7, #0x1c
	movs r0, #0x24
	adds r0, r0, r4
	mov r8, r0
	adds r0, r7, #0
	movs r1, #7
_0800589A:
	strb r3, [r0]
	strb r3, [r0, #8]
	strb r3, [r0, #0x10]
	adds r0, #1
	subs r1, #1
	cmp r1, #0
	bge _0800589A
	adds r0, r4, #0
	adds r0, #0x34
	movs r1, #0
	strb r1, [r0]
	ldrb r1, [r2]
	lsls r1, r1, #0x18
	adds r5, r0, #0
	adds r6, r4, #0
	adds r6, #0x39
	cmp r1, #0
	blt _08005984
	lsrs r1, r1, #0x18
	cmp r1, #0
	beq _080059B2
	cmp r1, #0x3c
	bne _080058DC
	b _080059AA
_080058CA:
	adds r0, r4, #0
	adds r1, r2, #0
	bl TextBoxChoice_ParseTag
	adds r2, r0, #0
	ldrb r0, [r2]
	cmp r0, #0
	beq _080059B2
	b _08005998
_080058DC:
	ldrb r0, [r2]
	cmp r0, #0xa
	bne _08005922
	adds r1, r4, #0
	adds r1, #0x3b
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	ldrb r0, [r5]
	ldrb r1, [r6]
	cmp r0, r1
	bhs _08005980
	mov r3, r8
	adds r1, r3, r0
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _08005904
	subs r0, #1
	b _08005906
_08005904:
	movs r0, #0
_08005906:
	strb r0, [r1]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r6]
	cmp r0, r1
	bhs _08005980
	ldrb r0, [r5]
	adds r0, r7, r0
	ldrb r1, [r4, #0x1b]
	strb r1, [r0]
	b _08005980
_08005922:
	cmp r0, #0x1f
	bne _0800596E
	adds r0, r2, #0
	bl FUN_08048afc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _0800594C @ =0x0000FFFF
	cmp r1, r0
	bne _08005950
_08005936:
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	b _080059B2
	.align 2, 0
_0800594C: .4byte 0x0000FFFF
_08005950:
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08005936
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _080059B2
_0800596E:
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08005980:
	adds r2, #1
	b _08005998
_08005984:
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	adds r2, #2
_08005998:
	ldrb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _08005984
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _080059B2
	cmp r0, #0x3c
	bne _080058DC
_080059AA:
	adds r2, #1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080058CA
_080059B2:
	ldrb r0, [r5]
	ldrb r6, [r6]
	cmp r0, r6
	bhs _080059CC
	mov r3, r8
	adds r2, r3, r0
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _080059C8
	subs r1, r0, #1
	b _080059CA
_080059C8:
	movs r1, #0
_080059CA:
	strb r1, [r2]
_080059CC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
