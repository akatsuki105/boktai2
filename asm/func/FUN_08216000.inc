	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	bl FUN_0822b644
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r1, _08216054 @ =0x000012AC
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	ldr r2, _08216058 @ =0x000012BA
	adds r4, r4, r2
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	bl Textbox_LookupString
	adds r4, r0, #0
	movs r0, #0xa
	movs r1, #4
	movs r2, #0x10
	movs r3, #2
	bl FUN_0821b28c
	movs r0, #0xa
	movs r1, #4
	adds r2, r4, #0
	bl Video_DrawText
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08216054: .4byte 0x000012AC
_08216058: .4byte 0x000012BA
