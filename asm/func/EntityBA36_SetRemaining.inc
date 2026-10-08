	push {r4, lr}
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1024
	bl VM_GetValue
	adds r1, r0, #0
	b _080A1028
_080A1024:
	movs r1, #0xe1
	lsls r1, r1, #3
_080A1028:
	ldr r4, _080A1054 @ =0x03002C40
	ldr r0, [r4]
	strh r1, [r0, #0x18]
	lsls r0, r1, #0x10
	cmp r0, #0
	beq _080A104E
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	bne _080A1046
	movs r0, #0x49
	movs r1, #0
	bl TryAddItem
_080A1046:
	ldr r0, [r4]
	adds r0, #0x18
	bl FUN_0809c544
_080A104E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A1054: .4byte 0x03002C40
