	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0819E5AA
	movs r4, #0
_0819E584:
	lsls r0, r4, #1
	ldr r2, _0819E59C @ =0x00000EBC
	adds r1, r6, r2
	adds r5, r1, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0819E5A0
	bl VM_GetValue
	b _0819E5A2
	.align 2, 0
_0819E59C: .4byte 0x00000EBC
_0819E5A0:
	movs r0, #0
_0819E5A2:
	strh r0, [r5]
	adds r4, #1
	cmp r4, #3
	ble _0819E584
_0819E5AA:
	movs r1, #0
	movs r4, #3
	ldr r2, _0819E5D0 @ =0x00000EBA
	adds r0, r6, r2
_0819E5B2:
	strh r1, [r0]
	subs r0, #2
	subs r4, #1
	cmp r4, #0
	bge _0819E5B2
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _0819E5D4
	asrs r1, r0, #2
	b _0819E5DA
	.align 2, 0
_0819E5D0: .4byte 0x00000EBA
_0819E5D4:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_0819E5DA:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	subs r0, r0, r1
	movs r2, #0xeb
	lsls r2, r2, #4
	adds r1, r6, r2
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
