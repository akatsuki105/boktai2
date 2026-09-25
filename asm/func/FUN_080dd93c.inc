	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r0, _080DD978 @ =0x03000170
	ldr r0, [r0]
	cmp r0, #0
	bne _080DD954
	bl AttackBoxManager_Create
	cmp r0, #0
	beq _080DDA46
_080DD954:
	bl AttackBoxManager_Alloc
	adds r5, r0, #0
	cmp r5, #0
	beq _080DDA46
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080DD9B2
	bl VM_GetPC
	cmp r0, #0
	beq _080DD97C
	bl Script_GetValue
	adds r1, r0, #0
	b _080DD97E
	.align 2, 0
_080DD978: .4byte 0x03000170
_080DD97C:
	movs r1, #0
_080DD97E:
	adds r0, r5, #0
	adds r0, #0x50
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD992
	bl Script_GetValue
	b _080DD994
_080DD992:
	movs r0, #0
_080DD994:
	adds r1, r5, #0
	adds r1, #0x52
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD9AA
	bl Script_GetValue
	adds r1, r0, #0
	b _080DD9AC
_080DD9AA:
	movs r1, #0
_080DD9AC:
	adds r0, r5, #0
	adds r0, #0x54
	strh r1, [r0]
_080DD9B2:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080DDA0C
	bl VM_GetPC
	cmp r0, #0
	beq _080DD9CE
	bl Script_GetValue
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b _080DD9D0
_080DD9CE:
	movs r0, #0
_080DD9D0:
	mov r8, r0
	bl VM_GetPC
	cmp r0, #0
	beq _080DD9E4
	bl Script_GetValue
	lsls r0, r0, #0x10
	asrs r7, r0, #0x10
	b _080DD9E6
_080DD9E4:
	movs r7, #0
_080DD9E6:
	bl VM_GetPC
	cmp r0, #0
	beq _080DD9F8
	bl Script_GetValue
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	b _080DD9FA
_080DD9F8:
	movs r6, #0
_080DD9FA:
	bl VM_GetPC
	cmp r0, #0
	beq _080DDA14
	bl Script_GetValue
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	b _080DDA16
_080DDA0C:
	movs r0, #0
	mov r8, r0
	movs r7, #0
	movs r6, #0
_080DDA14:
	movs r4, #0
_080DDA16:
	movs r0, #0x63
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r5, #0x60]
	adds r2, r5, #0
	adds r2, #0x5d
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0x5c
	movs r0, #2
	strb r0, [r1]
	str r4, [sp]
	adds r0, r5, #0
	mov r1, r8
	adds r2, r7, #0
	adds r3, r6, #0
	bl AttackBox_Setup
_080DDA46:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
