	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A9554
	bl VM_GetValue
	b _080A9558
_080A9554:
	movs r0, #0xe1
	lsls r0, r0, #3
_080A9558:
	strh r0, [r4, #0x18]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A9568
	bl VM_GetValue
_080A9568:
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0809c544
	ldr r0, _080A9580 @ =0x03002C50
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A9580: .4byte 0x03002C50
