	push {r4, r5, lr}
	bl Entity3117_FindEntry
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5046
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5046
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x86
	strh r0, [r1]
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5046
	bl VM_GetValue
	adds r5, r4, #0
	adds r5, #0x88
	strh r0, [r5]
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5046
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x8c
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _080A5036
	adds r0, r4, #0
	adds r0, #0x54
	subs r1, #8
	ldrh r1, [r1]
	ldrh r2, [r5]
	adds r1, r1, r2
	bl Video_SetAuxSpritePltt
	b _080A5046
_080A5036:
	adds r1, r4, #0
	adds r1, #0x8a
	movs r0, #0
	strh r0, [r1]
	ldrb r1, [r4, #2]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #2]
_080A5046:
	pop {r4, r5}
	pop {r0}
	bx r0
