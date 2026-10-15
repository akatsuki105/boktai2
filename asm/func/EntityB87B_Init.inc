	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #0x69
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080C25DC
	bl VM_GetValue
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	b _080C25E4
_080C25DC:
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
_080C25E4:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080C25FE
	bl VM_GetValue
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	b _080C2606
_080C25FE:
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
_080C2606:
	adds r0, r4, #0
	bl FUN_080c1f88
	adds r0, r4, #0
	bl FUN_080c2034
	adds r0, r4, #0
	bl FUN_080c20fc
	adds r0, r4, #0
	bl FUN_080c250c
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C263C @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080C263C: .4byte 0x0000FFFF
