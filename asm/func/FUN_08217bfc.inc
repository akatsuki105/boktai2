	push {r4, r5, r6, lr}
	sub sp, #0x20
	ldr r1, _08217C60 @ =0x0000166C
	adds r6, r0, r1
	ldr r1, _08217C64 @ =0x00001FA4
	adds r0, r0, r1
	ldr r2, _08217C68 @ =0x04000008
	mov r1, sp
	bl CpuSet
	mov r4, sp
	movs r5, #4
_08217C14:
	ldrb r0, [r4]
	cmp r0, #0
	bne _08217C3A
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _08217C3A
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x54
	bl Textbox_LookupString
	ldrb r1, [r0]
	strb r1, [r4]
	ldrb r0, [r0, #1]
	strb r0, [r4, #1]
_08217C3A:
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _08217C14
	movs r0, #0x12
	movs r1, #1
	movs r2, #0xa
	movs r3, #2
	bl FUN_0821b28c
	movs r0, #0x12
	movs r1, #1
	mov r2, sp
	bl Video_DrawText
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08217C60: .4byte 0x0000166C
_08217C64: .4byte 0x00001FA4
_08217C68: .4byte 0x04000008
