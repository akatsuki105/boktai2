	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809BEEC
	bl FUN_0823d340
	str r0, [r4, #0x40]
_0809BEEC:
	movs r0, #0x77
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809BEFC
	bl FUN_0823d340
	str r0, [r4, #0x44]
_0809BEFC:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809BF0C
	bl FUN_0823d340
	str r0, [r4, #0x48]
_0809BF0C:
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809BF1C
	bl FUN_0823d340
	str r0, [r4, #0x4c]
_0809BF1C:
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809BF2C
	bl FUN_0823d340
	str r0, [r4, #0x50]
_0809BF2C:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809BF3C
	bl FUN_0823d340
	str r0, [r4, #0x54]
_0809BF3C:
	movs r0, #0x45
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809BF4C
	bl FUN_0823d340
	str r0, [r4, #0x58]
_0809BF4C:
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809BF5C
	bl VM_GetValueSafe2
	str r0, [r4, #0x5c]
_0809BF5C:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _0809BF78
	bl VM_GetValue
	ldr r2, _0809BF74 @ =0x00003FA0
	adds r1, r4, r2
	strb r0, [r1]
	b _0809BF7E
	.align 2, 0
_0809BF74: .4byte 0x00003FA0
_0809BF78:
	ldr r2, _0809BF84 @ =0x00003FA0
	adds r0, r4, r2
	strb r1, [r0]
_0809BF7E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809BF84: .4byte 0x00003FA0
