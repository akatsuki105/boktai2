	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _080C252C
	movs r2, #0x89
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	b _080C2580
_080C252C:
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C25B2
	bl FUN_0823d340
	movs r1, #0x86
	lsls r1, r1, #2
	adds r6, r5, r1
	str r0, [r6]
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C25B2
	bl VM_GetValue
	movs r2, #0x89
	lsls r2, r2, #2
	adds r4, r5, r2
	strh r0, [r4]
	bl VM_GetValue
	ldrh r1, [r4]
	adds r1, r1, r0
	subs r1, #1
	ldr r2, _080C2594 @ =0x00000226
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _080C2598 @ =0x0000EFDA
	bl MessageWindow_SetBgPltt
	ldr r0, [r6]
	bl MessageWindow_Start
	movs r0, #1
	bl MessageWindow_SetInstant
	ldrh r0, [r4]
	bl MessageWindow_ShowLine
_080C2580:
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C25A0
	bl VM_GetValue
	ldr r2, _080C259C @ =0x0000022A
	adds r1, r5, r2
	b _080C25A6
	.align 2, 0
_080C2594: .4byte 0x00000226
_080C2598: .4byte 0x0000EFDA
_080C259C: .4byte 0x0000022A
_080C25A0:
	ldr r0, _080C25B8 @ =0x0000022A
	adds r1, r5, r0
	movs r0, #0x3c
_080C25A6:
	strh r0, [r1]
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
_080C25B2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C25B8: .4byte 0x0000022A
