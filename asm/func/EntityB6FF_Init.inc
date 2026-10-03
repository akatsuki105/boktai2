	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080ACB14
	adds r4, r7, #0
	adds r4, #0x1c
	movs r5, #2
_080ACAF8:
	bl VM_GetValue
	strh r0, [r4]
	bl VM_GetValue
	strh r0, [r4, #2]
	bl VM_GetValue
	strh r0, [r4, #4]
	adds r4, #0xc
	subs r5, #1
	cmp r5, #0
	bge _080ACAF8
	b _080ACB2A
_080ACB14:
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x1c
	movs r5, #2
_080ACB1C:
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	adds r0, #0xc
	subs r5, #1
	cmp r5, #0
	bge _080ACB1C
_080ACB2A:
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080ACB70
	ldr r6, _080ACB64 @ =0x030046B8
	adds r4, r7, #0
	adds r4, #0x24
	movs r5, #2
_080ACB3C:
	bl VM_GetValue
	strh r0, [r4]
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _080ACB68 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _080ACB6C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	strh r0, [r4, #2]
	adds r4, #0xc
	subs r5, #1
	cmp r5, #0
	bge _080ACB3C
	b _080ACBA0
	.align 2, 0
_080ACB64: .4byte 0x030046B8
_080ACB68: .4byte 0x000003FF
_080ACB6C: .4byte 0x0203B400
_080ACB70:
	movs r0, #0x20
	mov ip, r0
	ldr r6, _080ACBC0 @ =0x0203B400
	ldr r2, _080ACBC4 @ =0x030046B8
	adds r1, r7, #0
	adds r1, #0x24
	ldr r4, _080ACBC8 @ =0x000003FF
	movs r3, #0x1f
	movs r5, #2
_080ACB82:
	mov r0, ip
	strh r0, [r1]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r3
	strh r0, [r1, #2]
	adds r1, #0xc
	subs r5, #1
	cmp r5, #0
	bge _080ACB82
_080ACBA0:
	movs r5, #2
_080ACBA2:
	subs r5, #1
	cmp r5, #0
	bge _080ACBA2
	adds r0, r7, #0
	bl FUN_080aca60
	ldr r0, _080ACBCC @ =0x00003969
	adds r1, r7, #0
	movs r2, #0
	bl Registry_Add
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080ACBC0: .4byte 0x0203B400
_080ACBC4: .4byte 0x030046B8
_080ACBC8: .4byte 0x000003FF
_080ACBCC: .4byte 0x00003969
