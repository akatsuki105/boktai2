	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	mov r8, r3
	movs r0, #0x8c
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	bne _080115A4
	movs r0, #1
	rsbs r0, r0, #0
	b _080115F8
_080115A4:
	adds r0, r5, #0
	movs r1, #0x8c
	bl ClearMemory
	adds r0, r4, #0
	bl VM_ParseStringRef
	bl Textbox_LookupString
	str r0, [r5, #0x74]
	str r7, [r5, #0x78]
	ldr r0, _08011604 @ =0x0008C159
	str r0, [r5, #0x7c]
	adds r0, r5, #0
	adds r0, #0x18
	adds r1, r6, #0
	movs r2, #0x30
	bl PasswordDecoder_StripTags
	adds r0, r5, #0
	bl FUN_080111a4
	adds r4, r0, #0
	cmp r4, #0
	blt _080115F0
	adds r0, r5, #0
	bl PasswordDecoder_Parse
	adds r4, r0, #0
	cmp r4, #0
	blt _080115F0
	adds r0, r5, #0
	mov r1, r8
	bl PasswordDecoder_SaveChanges
	adds r0, r5, #0
	bl PasswordDecoder_NOP
_080115F0:
	adds r0, r5, #0
	bl Free
	adds r0, r4, #0
_080115F8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08011604: .4byte 0x0008C159
