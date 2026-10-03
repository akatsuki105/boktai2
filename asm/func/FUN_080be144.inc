	push {r4, r5, lr}
	sub sp, #0x34
	adds r4, r0, #0
	ldr r0, _080BE1B0 @ =0x0000C091
	ldr r1, _080BE1B4 @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	ldr r0, _080BE1B8 @ =0x00001638
	adds r4, r4, r0
	str r2, [r4]
	movs r5, #0
	str r5, [sp, #0x30]
	str r5, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0x30
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	ldr r1, [r4]
	movs r0, #0
	movs r2, #4
	bl Video_SetBGLayer
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #3
	add r1, sp, #0xc
	bl FUN_08242b28
	add r0, sp, #0xc
	ldrb r0, [r0, #1]
	cmp r0, #4
	bne _080BE1A8
	ldr r0, _080BE1BC @ =0x03003ED0
	ldr r0, [r0, #0x2c]
	ldr r1, _080BE1C0 @ =0x00000392
	adds r0, r0, r1
	ldr r2, _080BE1C4 @ =0x0000F06E
	adds r1, r2, #0
	strh r1, [r0]
_080BE1A8:
	add sp, #0x34
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BE1B0: .4byte 0x0000C091
_080BE1B4: .4byte 0x00009F57
_080BE1B8: .4byte 0x00001638
_080BE1BC: .4byte 0x03003ED0
_080BE1C0: .4byte 0x00000392
_080BE1C4: .4byte 0x0000F06E
