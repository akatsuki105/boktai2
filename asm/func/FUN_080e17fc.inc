	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080E1832
	bl VM_GetPC
	cmp r0, #0
	beq _080E181C
	bl Script_GetValue
	b _080E181E
_080E181C:
	movs r0, #0
_080E181E:
	strh r0, [r4, #0x18]
	bl VM_GetPC
	cmp r0, #0
	beq _080E182E
	bl Script_GetValue
	b _080E1834
_080E182E:
	movs r0, #0
	b _080E1834
_080E1832:
	strh r0, [r4, #0x18]
_080E1834:
	strh r0, [r4, #0x1a]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _080E186E
	adds r6, r4, #0
	adds r6, #0x2a
	movs r0, #0x2b
	adds r0, r0, r4
	mov r8, r0
	adds r7, r4, #0
	adds r7, #0x1c
	movs r5, #1
_080E1850:
	bl VM_GetPC
	cmp r0, #0
	beq _080E1862
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _080E1864
_080E1862:
	movs r0, #0
_080E1864:
	stm r7!, {r0}
	subs r5, #1
	cmp r5, #0
	bge _080E1850
	b _080E188A
_080E186E:
	adds r6, r4, #0
	adds r6, #0x2a
	movs r1, #0x2b
	adds r1, r1, r4
	mov r8, r1
	adds r1, r4, #0
	adds r1, #0x1c
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0x20
_080E1882:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _080E1882
_080E188A:
	movs r0, #0x75
	bl prepare_08231510
	cmp r0, #0
	beq _080E18B8
	bl VM_GetPC
	cmp r0, #0
	beq _080E18A2
	bl Script_GetValue
	b _080E18A4
_080E18A2:
	movs r0, #1
_080E18A4:
	strb r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _080E18B4
	bl Script_GetValue
	b _080E18BE
_080E18B4:
	movs r0, #1
	b _080E18BE
_080E18B8:
	movs r0, #1
	strb r0, [r6]
	movs r0, #8
_080E18BE:
	mov r1, r8
	strb r0, [r1]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	movs r1, #0
	strh r0, [r4, #0x24]
	strh r1, [r4, #0x26]
	strh r1, [r4, #0x28]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
