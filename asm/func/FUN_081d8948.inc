	push {r4, r5, r6, r7, lr}
	ldr r0, _081D89AC @ =0x030001A0
	ldr r0, [r0]
	cmp r0, #0
	bne _081D895A
	bl Entity7B9F_Create
	cmp r0, #0
	beq _081D89EC
_081D895A:
	bl Entity7B9F_AllocElem
	adds r5, r0, #0
	cmp r5, #0
	beq _081D89EC
	movs r1, #2
	bl FUN_081d8714
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081D8986
	bl VM_GetValue
	strh r0, [r5, #0x1c]
	bl VM_GetValue
	strh r0, [r5, #0x1e]
	bl VM_GetValue
	strh r0, [r5, #0x20]
_081D8986:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r5, #0
	adds r1, #0xcc
	strh r0, [r1]
	movs r0, #0x61
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081D89B0
	bl VM_GetValue
	adds r7, r0, #0
	bl VM_GetValue
	adds r6, r0, #0
	b _081D89B4
	.align 2, 0
_081D89AC: .4byte 0x030001A0
_081D89B0:
	movs r7, #0x64
	movs r6, #0x64
_081D89B4:
	adds r1, r5, #0
	adds r1, #0xd4
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xd5
	strb r2, [r0]
	adds r1, #4
	ldr r0, _081D89F4 @ =FUN_081d836c
	str r0, [r1]
	adds r4, r5, #0
	adds r4, #0x8c
	subs r1, #0xbc
	adds r0, r4, #0
	bl ParticleShadow_Init
	adds r1, r5, #0
	adds r1, #0xd2
	strh r0, [r1]
	adds r0, r4, #0
	bl ParticleShadow_Hide
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl FUN_081d88a8
_081D89EC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D89F4: .4byte FUN_081d836c
