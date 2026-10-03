	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080B1D8A
	bl VM_GetValue
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r1, r4, r2
	strh r0, [r1]
	bl VM_GetValue
	ldr r5, _080B1DD8 @ =0x00000502
	adds r1, r4, r5
	strh r0, [r1]
	bl VM_GetValue
	ldr r2, _080B1DDC @ =0x00000504
	adds r1, r4, r2
	strh r0, [r1]
_080B1D8A:
	movs r5, #0xa1
	lsls r5, r5, #3
	adds r2, r4, r5
	movs r0, #0xa0
	lsls r0, r0, #3
	adds r3, r4, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r5, [r2]
	adds r1, r0, r5
	strh r1, [r2]
	ldr r2, _080B1DE0 @ =0x0000050C
	adds r1, r4, r2
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	movs r0, #0xa2
	lsls r0, r0, #3
	adds r2, r4, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r2, _080B1DE4 @ =0x00000514
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #0x14
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B1DD8: .4byte 0x00000502
_080B1DDC: .4byte 0x00000504
_080B1DE0: .4byte 0x0000050C
_080B1DE4: .4byte 0x00000514
