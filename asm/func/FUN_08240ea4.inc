	push {r4, r5, r6, lr}
	sub sp, #8
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08240EE0
	bl VM_GetPC
	cmp r0, #0
	beq _08240EC4
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _08240EC6
_08240EC4:
	movs r0, #0
_08240EC6:
	adds r6, r0, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08240EDA
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _08240EDC
_08240EDA:
	movs r0, #0
_08240EDC:
	adds r5, r0, #0
	b _08240EE4
_08240EE0:
	movs r6, #0
	movs r5, #0
_08240EE4:
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0x66
	movs r1, #1
	bl VM_GetKeywordValue
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r3, #0
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r2, #0
	adds r2, r4, #0
	bl FUN_08240bcc
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
