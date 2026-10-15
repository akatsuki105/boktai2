	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x98
	movs r1, #1
	strb r1, [r0]
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A6204
	bl VM_GetValue
	adds r5, r0, #0
	b _080A6206
_080A6204:
	movs r5, #0
_080A6206:
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A6214
	bl VM_GetValue
_080A6214:
	adds r1, r4, #0
	adds r1, #0x99
	strb r0, [r1]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A6232
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xa8
	str r0, [r1]
	b _080A6238
_080A6232:
	adds r0, r4, #0
	adds r0, #0xa8
	str r1, [r0]
_080A6238:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a6048
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a6110
	ldr r1, _080A6254 @ =0x0300014C
	str r4, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A6254: .4byte 0x0300014C
