	push {r4, r5, lr}
	ldr r0, _08240F64 @ =0x03001700
	ldr r5, [r0]
	cmp r5, #0
	beq _08240F8C
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08240F8C
	b _08240F84
	.align 2, 0
_08240F64: .4byte 0x03001700
_08240F68:
	bl Script_GetValue
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08240f20
	cmp r0, #0
	bge _08240F84
	lsls r1, r0, #2
	adds r0, r5, #0
	adds r0, #0x98
	subs r0, r0, r1
	str r4, [r0]
_08240F84:
	bl VM_GetPC
	cmp r0, #0
	bne _08240F68
_08240F8C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
