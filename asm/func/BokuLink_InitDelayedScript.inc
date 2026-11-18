	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r0, #0x78
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _081B397C
	bl VM_GetPC
	cmp r0, #0
	beq _081B394A
	bl VM_GetValue
	adds r1, r0, #0
	b _081B394C
_081B394A:
	movs r1, #0
_081B394C:
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081B3964
	bl VM_GetValue
	adds r2, r0, #0
	b _081B3966
_081B3964:
	movs r2, #0
_081B3966:
	ldr r1, _081B3974 @ =0x0000065A
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _081B3978 @ =0x0000065B
	b _081B398E
	.align 2, 0
_081B3974: .4byte 0x0000065A
_081B3978: .4byte 0x0000065B
_081B397C:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	ldr r2, _081B3998 @ =0x0000065A
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
_081B398E:
	adds r0, r4, r2
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B3998: .4byte 0x0000065A
