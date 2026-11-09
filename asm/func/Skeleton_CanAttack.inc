	push {lr}
	mov ip, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r3, [r0]
	movs r0, #0x90
	lsls r0, r0, #3
	add r0, ip
	ldrh r0, [r0]
	cmp r0, #2
	beq _081059E0
	cmp r0, #2
	bgt _08105916
	cmp r0, #0
	beq _08105922
	b _08105AB0
_08105916:
	cmp r0, #5
	beq _08105922
	cmp r0, #8
	bne _08105920
	b _08105A4C
_08105920:
	b _08105AB0
_08105922:
	ldr r0, _08105930 @ =0x000001DF
	add r0, ip
	ldrb r0, [r0]
	cmp r0, #5
	bne _08105938
	ldr r1, _08105934 @ =0x00000744
	b _08105A9A
	.align 2, 0
_08105930: .4byte 0x000001DF
_08105934: .4byte 0x00000744
_08105938:
	cmp r0, #7
	bne _08105978
	movs r0, #0xc2
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08105964 @ =0x00000546
	add r0, ip
	ldrh r0, [r0]
	cmp r1, r0
	blt _08105970
	movs r1, #0x80
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08105968
	movs r0, #1
	b _0810596A
	.align 2, 0
_08105964: .4byte 0x00000546
_08105968:
	movs r0, #0
_0810596A:
	cmp r0, #0
	bne _08105970
	b _08105A98
_08105970:
	ldr r1, _08105974 @ =0x00000744
	b _08105A9A
	.align 2, 0
_08105974: .4byte 0x00000744
_08105978:
	movs r0, #0xf2
	lsls r0, r0, #1
	add r0, ip
	ldr r2, _081059D0 @ =0x00000734
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08105998
	ldr r1, _081059D4 @ =0x00000744
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08105998
	b _08105AA4
_08105998:
	movs r0, #0xf2
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0xe7
	lsls r2, r2, #3
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081059B8
	ldr r1, _081059D8 @ =0x00000746
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08105AA4
_081059B8:
	movs r0, #0xf2
	lsls r0, r0, #1
	add r0, ip
	ldr r2, _081059DC @ =0x0000073C
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08105AB0
	movs r1, #0xe9
	lsls r1, r1, #3
	b _08105A9A
	.align 2, 0
_081059D0: .4byte 0x00000734
_081059D4: .4byte 0x00000744
_081059D8: .4byte 0x00000746
_081059DC: .4byte 0x0000073C
_081059E0:
	movs r0, #0xc2
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08105A28 @ =0x00000546
	add r0, ip
	ldrh r0, [r0]
	cmp r1, r0
	bge _08105A34
	movs r0, #0xf2
	lsls r0, r0, #1
	add r0, ip
	ldr r2, _08105A2C @ =0x00000734
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08105A12
	ldr r1, _08105A30 @ =0x00000744
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08105AA4
_08105A12:
	movs r0, #0xf2
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0xe7
	lsls r2, r2, #3
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08105AB0
	b _08105A98
	.align 2, 0
_08105A28: .4byte 0x00000546
_08105A2C: .4byte 0x00000734
_08105A30: .4byte 0x00000744
_08105A34:
	ldr r1, _08105A48 @ =0x00000744
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08105AA4
	movs r1, #0xe9
	lsls r1, r1, #3
	b _08105A9A
	.align 2, 0
_08105A48: .4byte 0x00000744
_08105A4C:
	movs r0, #0xc2
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08105A80 @ =0x00000546
	add r0, ip
	ldrh r0, [r0]
	cmp r1, r0
	bge _08105A8C
	ldr r1, _08105A84 @ =0x00000744
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08105AA4
	ldr r1, _08105A88 @ =0x00000746
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08105AA4
	movs r1, #0xe9
	lsls r1, r1, #3
	b _08105A9A
	.align 2, 0
_08105A80: .4byte 0x00000546
_08105A84: .4byte 0x00000744
_08105A88: .4byte 0x00000746
_08105A8C:
	ldr r1, _08105AA8 @ =0x00000744
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08105AA4
_08105A98:
	ldr r1, _08105AAC @ =0x00000746
_08105A9A:
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08105AB0
_08105AA4:
	movs r0, #1
	b _08105AB2
	.align 2, 0
_08105AA8: .4byte 0x00000744
_08105AAC: .4byte 0x00000746
_08105AB0:
	movs r0, #0
_08105AB2:
	pop {r1}
	bx r1
	.align 2, 0
