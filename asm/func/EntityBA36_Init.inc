	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1120
	bl VM_GetValue
	b _080A1124
_080A1120:
	movs r0, #0xe1
	lsls r0, r0, #3
_080A1124:
	strh r0, [r4, #0x18]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1134
	bl VM_GetValue
_080A1134:
	str r0, [r4, #0x1c]
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	beq _080A1156
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	bne _080A114E
	movs r0, #0x49
	movs r1, #0
	bl TryAddItem
_080A114E:
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0809c544
_080A1156:
	ldr r0, _080A1164 @ =0x03002C40
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A1164: .4byte 0x03002C40
