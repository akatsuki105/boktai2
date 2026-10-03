	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r0, #0x57
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080BE6AC
	bl VM_GetValue
	adds r5, r0, #0
	b _080BE6AE
_080BE6AC:
	movs r5, #0
_080BE6AE:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080BE75C
	movs r4, #0
	movs r6, #0
	movs r7, #0
	cmp r7, r5
	bge _080BE720
	ldr r0, _080BE6E4 @ =0x08DA9E68
	mov sb, r0
_080BE6C6:
	bl VM_GetValue
	adds r1, r0, #0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, sb
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _080BE700
	cmp r0, #1
	bgt _080BE6E8
	cmp r0, #0
	beq _080BE6EE
	b _080BE71A
	.align 2, 0
_080BE6E4: .4byte 0x08DA9E68
_080BE6E8:
	cmp r0, #2
	beq _080BE710
	b _080BE71A
_080BE6EE:
	ldr r0, _080BE6FC @ =0x0000165C
	add r0, r8
	adds r0, r0, r4
	strb r1, [r0]
	adds r4, #1
	b _080BE71A
	.align 2, 0
_080BE6FC: .4byte 0x0000165C
_080BE700:
	ldr r0, _080BE70C @ =0x0000166C
	add r0, r8
	adds r0, r0, r6
	strb r1, [r0]
	adds r6, #1
	b _080BE71A
	.align 2, 0
_080BE70C: .4byte 0x0000166C
_080BE710:
	ldr r0, _080BE7A0 @ =0x0000167C
	add r0, r8
	adds r0, r0, r7
	strb r1, [r0]
	adds r7, #1
_080BE71A:
	subs r5, #1
	cmp r5, #0
	bne _080BE6C6
_080BE720:
	cmp r4, #0xb
	bgt _080BE734
	ldr r1, _080BE7A4 @ =0x0000165C
	add r1, r8
	movs r2, #0
_080BE72A:
	adds r0, r1, r4
	strb r2, [r0]
	adds r4, #1
	cmp r4, #0xb
	ble _080BE72A
_080BE734:
	cmp r6, #0xb
	bgt _080BE748
	ldr r1, _080BE7A8 @ =0x0000166C
	add r1, r8
	movs r2, #0
_080BE73E:
	adds r0, r1, r6
	strb r2, [r0]
	adds r6, #1
	cmp r6, #0xb
	ble _080BE73E
_080BE748:
	cmp r7, #0xb
	bgt _080BE75C
	ldr r1, _080BE7A0 @ =0x0000167C
	add r1, r8
	movs r2, #0
_080BE752:
	adds r0, r1, r7
	strb r2, [r0]
	adds r7, #1
	cmp r7, #0xb
	ble _080BE752
_080BE75C:
	movs r0, #0x77
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080BE770
	bl FUN_0823d340
	ldr r1, _080BE7AC @ =0x00001644
	add r1, r8
	str r0, [r1]
_080BE770:
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080BE794
	bl FUN_0823d340
	ldr r4, _080BE7B0 @ =0x00001648
	add r4, r8
	str r0, [r4]
	cmp r0, #0
	beq _080BE794
	bl VM_ParseStringRef
	adds r0, #1
	bl Textbox_LookupString
	str r0, [r4]
_080BE794:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BE7A0: .4byte 0x0000167C
_080BE7A4: .4byte 0x0000165C
_080BE7A8: .4byte 0x0000166C
_080BE7AC: .4byte 0x00001644
_080BE7B0: .4byte 0x00001648
