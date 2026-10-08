	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _08096614 @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r1, _08096618 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl TextBox_SetRect
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #7
	bl FUN_0808a3c4
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0809657E
	movs r0, #0x12
	movs r1, #4
	movs r2, #0xb
	movs r3, #0xb
	bl FUN_0808b9c4
	movs r0, #8
	movs r1, #9
	movs r2, #5
	movs r3, #6
	bl FUN_0808b9c4
_0809657E:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	adds r0, r4, #0
	bl FUN_0808b38c
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _0809661C @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	ldr r0, _08096620 @ =0x0000156C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08096624 @ =0x00001564
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	movs r2, #0x9f
	movs r3, #1
	bl MainSprite_SetPose
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080964ac
	adds r0, r4, #0
	bl FUN_080963f4
	adds r0, r4, #0
	bl weapon_08094f88
	bl FUN_08049f5c
	ldr r0, _08096628 @ =0x0000EFDA
	bl TextBox_SetBgPltt
	adds r0, r4, #0
	bl FUN_08094eb0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808c61c
	adds r0, r4, #0
	movs r1, #0
	bl weapon_08095820
	ldr r1, _0809662C @ =FUN_08095ae8
	adds r0, r4, #0
	movs r2, #0
	bl EntityCC28_SetState
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096614: .4byte 0x00004014
_08096618: .4byte 0x00004018
_0809661C: .4byte 0x00000F56
_08096620: .4byte 0x0000156C
_08096624: .4byte 0x00001564
_08096628: .4byte 0x0000EFDA
_0809662C: .4byte FUN_08095ae8
