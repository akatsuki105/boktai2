	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe8
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	ldr r1, _08215944 @ =0x00000E84
	adds r4, r4, r1
	ldr r1, [r4]
	adds r0, r0, r1
	bl Textbox_LookupString
	adds r5, r0, #0
	movs r0, #9
	movs r1, #0xa
	movs r2, #0x12
	movs r3, #2
	bl FUN_0821b28c
	movs r0, #9
	movs r1, #0xa
	adds r2, r5, #0
	bl Video_DrawText
	ldr r0, _08215948 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0821594C @ =0x00000944
	adds r0, r0, r1
	ldr r1, [r4]
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08215944: .4byte 0x00000E84
_08215948: .4byte 0x030046A0
_0821594C: .4byte 0x00000944
