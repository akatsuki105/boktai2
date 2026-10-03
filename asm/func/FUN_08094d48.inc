	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r0, r1, #0
	bl VM_ParseStringRef
	adds r4, r0, #0
	movs r0, #0x42
	adds r0, r0, r4
	mov r8, r0
	ldrb r0, [r7, #3]
	cmp r0, #0
	beq _08094D6E
	adds r1, r0, #0
	movs r0, #0
	bl FUN_08049e6c
_08094D6E:
	ldrb r1, [r7, #4]
	movs r0, #1
	bl FUN_08049e6c
	ldrb r0, [r7]
	add r0, r8
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r6, #0
	ldrb r0, [r7, #0x18]
	cmp r0, #0
	beq _08094D9C
	adds r0, #0x42
	add r0, r8
	bl Textbox_LookupString
	adds r1, r0, #0
	movs r0, #0
	bl FUN_08049eb0
	b _08094DAC
_08094D9C:
	adds r0, r4, #0
	adds r0, #0x84
	bl Textbox_LookupString
	adds r1, r0, #0
	movs r0, #0
	bl FUN_08049eb0
_08094DAC:
	adds r6, #1
	adds r4, r7, #0
	adds r4, #0x1c
	movs r5, #1
_08094DB4:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08094DCC
	adds r0, #0x42
	add r0, r8
	bl Textbox_LookupString
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_08049eb0
	adds r6, #1
_08094DCC:
	adds r4, #4
	subs r5, #1
	cmp r5, #0
	bge _08094DB4
	ldrb r2, [r7, #0xc]
	cmp r2, #0
	bne _08094DEC
	ldr r0, _08094DE8 @ =0x03002C20
	strb r2, [r0]
	adds r1, r6, #1
	mov sb, r1
	mov ip, r0
	b _08094E3A
	.align 2, 0
_08094DE8: .4byte 0x03002C20
_08094DEC:
	movs r3, #0
	movs r5, #0
	adds r0, r6, #1
	mov sb, r0
	ldr r1, _08094E6C @ =0x03002C20
	mov ip, r1
	mov r4, ip
	adds r2, r7, #0
	adds r2, #0xc
_08094DFE:
	adds r1, r3, r4
	ldrb r0, [r2]
	strb r0, [r1]
	adds r3, #1
	adds r2, #1
	adds r5, #1
	cmp r5, #0xb
	bgt _08094E14
	ldrb r0, [r2]
	cmp r0, #0
	bne _08094DFE
_08094E14:
	adds r1, r3, r4
	movs r0, #0x81
	strb r0, [r1]
	adds r3, #1
	adds r1, r3, r4
	movs r0, #0xf
	strb r0, [r1]
	adds r3, #1
	adds r1, r3, r4
	movs r0, #0x80
	strb r0, [r1]
	adds r3, #1
	adds r1, r3, r4
	movs r0, #0x56
	strb r0, [r1]
	adds r3, #1
	adds r1, r3, r4
	movs r0, #0
	strb r0, [r1]
_08094E3A:
	adds r0, r6, #0
	mov r1, ip
	bl FUN_08049eb0
	mov r6, sb
	cmp r6, #3
	bgt _08094E5E
_08094E48:
	mov r0, r8
	adds r0, #0x42
	bl Textbox_LookupString
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_08049eb0
	adds r6, #1
	cmp r6, #3
	ble _08094E48
_08094E5E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08094E6C: .4byte 0x03002C20
